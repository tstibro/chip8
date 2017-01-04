#include "stdafx.h"
#include "Chip8.hpp"

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
#include "adapters/audio/chip8AudioAdapter.hpp"
#include "adapters/video/chip8VideoAdapter.hpp"

using namespace std;
using namespace chip8::core::memory;
using namespace chip8::core::cpu;
using namespace chip8::core::gpu;
using namespace chip8::adapter;
using namespace chip8::font;
using namespace chip8;

Chip8::Chip8(Chip8AudioAdapter *audioInterface, Chip8VideoAdapter *videoInterface)
{
	if (audioInterface == NULL)
	{
		throw std::invalid_argument("audioInterface is NULL");
	}
	if (videoInterface == NULL)
	{
		throw std::invalid_argument("videoInterface is NULL");
	}

	this->audioInterface = audioInterface;
	this->videoInterface = videoInterface;
	initialize();
	romLoaded = false;
}

Chip8::Chip8(Chip8VideoAdapter *videoInterface)
{
	if (videoInterface == NULL)
	{
		throw std::invalid_argument("videoInterface is NULL");
	}
	this->audioInterface = NULL;
	this->videoInterface = videoInterface;
	initialize();
	romLoaded = false;
}

Chip8::Chip8()
{
	this->audioInterface = NULL;
	this->videoInterface = NULL;
	initialize();
	romLoaded = false;
}

Chip8::~Chip8()
{
	delete keyboard;
	delete ram;
	delete gpuExchangeBuffer;
	delete gpu;
	delete cpu;
}

u32 Chip8::GetDisplayWidth()
{
	return DISPLAY_WIDTH;
}

u32 Chip8::GetDisplayHeight()
{
	return DISPLAY_HEIGHT;
}

void Chip8::initialize()
{
	keyboard = new Keyboard();
	gpu = new GPU();
	gpuExchangeBuffer = new u8[gpu->GetWidth() * gpu->GetHeight()];
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

void Chip8::updateAudio()
{
	// Audio might not be initialized
	if (audioInterface != NULL)
	{
		// When sound timer is not 0, sound is played
		u8 soundTimerValue = cpu->GetSoundTimerValue();
		if (soundTimerValue != 0 && playAudio)
		{
			audioInterface->PlaySound();
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
	if ((videoInterface != NULL) && gpu->IsRefreshRequested())
	{
		u8 width = gpu->GetWidth();
		u8 height = gpu->GetHeight();

		gpu->GetPixels(gpuExchangeBuffer);
		videoInterface->Display(gpuExchangeBuffer, width * height);
		gpu->ResetRefreshRequest();
	}
}

void Chip8::LoadROM(char *romFilePath)
{
	ProgramLoader programLoader;
	programLoader.LoadTo(ram, romFilePath);
	romLoaded = true;
}

/* CHIP8 Keyboard Layout
	1 2 3 C
	4 5 6 D
	7 8 9 E
	A 0 B F
*/
void Chip8::UpdateInput(u8 keyCode, bool pressed)
{
	keyboard->UpdateKeyState(keyCode % 16, pressed);
}

void Chip8::EmulateCycle(u32 msPassed)
{
	if (romLoaded)
	{
		updateTimers(msPassed);
		updateAudio();
		updateVideo();
		cpu->ExecuteInstruction();
	}
}
