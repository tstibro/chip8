/*
* chip8emulator.cpp
*
*  Created on: Aug 7, 2016
*      Author: Tomas Stibrany
*/
#include "chip8emulator.hpp"
#include <iostream>
#include <fstream>

#include "chip8Types.hpp"
#include "core/cpu/cpu.hpp"
#include "core/gpu/gpu.hpp"
#include "core/memory/ram.hpp"
#include "core/memory/programLoader.hpp"
#include "font/fontLoader.hpp"
#include "font/font.hpp"
#include "keyboard/keyboard.hpp"
#include "display/display.hpp"
#include "audio/audio.hpp"

using namespace std;
using namespace chip8::core::cpu;
using namespace chip8::core::gpu;
using namespace chip8::core::memory;
using namespace chip8::font;
using namespace chip8;

Chip8::Chip8()
{
	initialize();
	romLoaded = false;
}

Chip8::~Chip8()
{
	delete keyboard;
	delete display;
	delete audio;
	delete ram;
	delete gpuExchangeBuffer;
	delete gpu;
	delete cpu;
}

void Chip8::initialize()
{
	keyboard = new Keyboard();
	gpu = new GPU();
	gpuExchangeBuffer = new u8[gpu->GetWidth() * gpu->GetHeight()];
	display = new Display(gpu->GetWidth(), gpu->GetHeight(), 10);
	try
	{
		audio = new Audio("..\\Debug\\beepsfx.wav");
	}
	catch (runtime_error e)
	{
		// Disable audio
		audio = NULL;
	}
	playAudio = false;

	ram = new RAM();
	FontLoader fontLoader;
	font = new Font();
	fontLoader.LoadTo(ram, font);

	cpu = new CPU(ram, gpu, keyboard);
}

void Chip8::updateTimers(long long dt)
{
	while (dt > 0)
	{
		this->cpu->TimerTick();
		dt -= 1;
	}
}

/* Keyboard Layout

1 2 3 C       7 8 9 Q
4 5 6 D   =>  4 5 6 W
7 8 9 E       1 2 3 E
A 0 B F       A 0 S F

*/
void Chip8::updateKeys(const SDL_KeyboardEvent keyboardEvent)
{
	bool isKeyPressed = keyboardEvent.type == SDL_KEYDOWN;
	switch (keyboardEvent.keysym.scancode)
	{
	case SDL_SCANCODE_KP_0:
		keyboard->UpdateKeyState(0, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_1:
		keyboard->UpdateKeyState(7, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_2:
		keyboard->UpdateKeyState(8, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_3:
		keyboard->UpdateKeyState(9, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_4:
		keyboard->UpdateKeyState(4, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_5:
		keyboard->UpdateKeyState(5, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_6:
		keyboard->UpdateKeyState(6, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_7:
		keyboard->UpdateKeyState(1, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_8:
		keyboard->UpdateKeyState(2, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_9:
		keyboard->UpdateKeyState(3, isKeyPressed);
		break;
	case SDL_SCANCODE_Q:
		keyboard->UpdateKeyState(0x0d, isKeyPressed);
		break;
	case SDL_SCANCODE_W:
		keyboard->UpdateKeyState(0x0c, isKeyPressed);
		break;
	case SDL_SCANCODE_E:
		keyboard->UpdateKeyState(0x0e, isKeyPressed);
		break;
	case SDL_SCANCODE_F:
		keyboard->UpdateKeyState(0x0f, isKeyPressed);
		break;
	case SDL_SCANCODE_S:
		keyboard->UpdateKeyState(0x0b, isKeyPressed);
		break;
	case SDL_SCANCODE_A:
		keyboard->UpdateKeyState(0x0a, isKeyPressed);
		break;
	}
}

void Chip8::updateAudio()
{
	// Audio might not be initialized
	if (audio != NULL)
	{
		// When sound timer is not 0, sound is played
		u8 soundTimerValue = cpu->GetSoundTimerValue();
		if (soundTimerValue != 0 && playAudio)
		{
			audio->Play();
			playAudio = false;
		}
		if (soundTimerValue == 0)
		{
			playAudio = true;
		}
	}
}

void Chip8::updateVideo()
{
	if (gpu->IsRefreshRequested())
	{
		u8 width = gpu->GetWidth();
		u8 height = gpu->GetHeight();

		gpu->GetPixels(gpuExchangeBuffer);
		display->RefreshFrom(gpuExchangeBuffer, width * height);
		gpu->ResetRefreshRequest();
	}
}

void Chip8::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) > 0)
	{
		if (event.type == SDL_QUIT)
		{
			isRunning = false;
			break;
		}
		else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
		{
			updateKeys(event.key);
		}
	}
}

void Chip8::CreateWindow(char *windowTitle)
{
	display->CreateWindow(windowTitle);
}

void Chip8::LoadROM(char *filePath)
{
	ProgramLoader programLoader;
	programLoader.LoadTo(ram, filePath);
	romLoaded = true;
}

void Chip8::EmulateCycle()
{
	if (romLoaded)
	{
		isRunning = true;
		lastTimePoint = chrono::high_resolution_clock::now();
		long long timeAcc = 0;

		while (isRunning)
		{
			auto currentTime = chrono::high_resolution_clock::now();
			auto timeDelta = chrono::duration_cast<chrono::milliseconds>(currentTime - lastTimePoint).count();
			if (timeDelta > 0)
			{
				lastTimePoint = currentTime;
				timeAcc += timeDelta;

				if (timeAcc >= INPUT_UPDATE_INTERVAL)
				{
					timeAcc -= INPUT_UPDATE_INTERVAL;
					handleEvents();
				}
				updateTimers(timeDelta);
			}
			updateAudio();
			updateVideo();
			cpu->ExecuteInstruction();
		}
	}
}

