/*
 * chip8.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: Tomas Stibrany
 */
#include <iostream>
#include <chrono>

#include "../Chip8lib/Chip8.hpp"
#include "audio/audio.hpp"
#include "display/display.hpp"

#define EVENT_UPDATE_INTERVAL (1000 / 60)

using namespace std;
using namespace chip8;

void handleInputEvent(SDL_Event event, Chip8 *emulator);

int main(int argc, char **argv)
{
	Chip8 *emulator = NULL;

	SDLDisplay *display = new SDLDisplay(Chip8::GetDisplayWidth(), Chip8::GetDisplayHeight(), 10);
	SDLAudio *audio = NULL;
	try
	{
		audio = new SDLAudio("..\\Debug\\beepsfx.wav");
		emulator = new Chip8(audio, display);
	}
	catch (runtime_error e)
	{
		// Disable audio
		emulator = new Chip8(display);
	}

 	if(argc > 1)
	{
		display->CreateWindow("CHIP8 Emulator");
 		emulator->LoadROM(argv[1]);

		bool isRunning = true;
		auto lastTimePoint = chrono::high_resolution_clock::now();
		long long timeAcc = 0;

		while (isRunning)
		{
			auto currentTime = chrono::high_resolution_clock::now();
			auto timeDelta = chrono::duration_cast<chrono::milliseconds>(currentTime - lastTimePoint).count();
			if (timeDelta > 0)
			{
				lastTimePoint = currentTime;
				timeAcc += timeDelta;

				if (timeAcc >= EVENT_UPDATE_INTERVAL)
				{
					timeAcc -= EVENT_UPDATE_INTERVAL;
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
							handleInputEvent(event, emulator);
						}
					}
				}
			}
 			emulator->EmulateCycle(timeDelta);
		}
	}
	else
	{
		delete emulator;
		return -1;
	}
	delete emulator;
	return 0;
}

void handleInputEvent(SDL_Event event, Chip8 *emulator)
{
	bool isKeyPressed = event.key.type == SDL_KEYDOWN;
	switch (event.key.keysym.scancode)
	{
	case SDL_SCANCODE_KP_0:
		emulator->UpdateInput(0, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_1:
		emulator->UpdateInput(7, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_2:
		emulator->UpdateInput(8, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_3:
		emulator->UpdateInput(9, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_4:
		emulator->UpdateInput(4, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_5:
		emulator->UpdateInput(5, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_6:
		emulator->UpdateInput(6, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_7:
		emulator->UpdateInput(1, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_8:
		emulator->UpdateInput(2, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_9:
		emulator->UpdateInput(3, isKeyPressed);
		break;
	case SDL_SCANCODE_Q:
		emulator->UpdateInput(0x0d, isKeyPressed);
		break;
	case SDL_SCANCODE_W:
		emulator->UpdateInput(0x0c, isKeyPressed);
		break;
	case SDL_SCANCODE_E:
		emulator->UpdateInput(0x0e, isKeyPressed);
		break;
	case SDL_SCANCODE_F:
		emulator->UpdateInput(0x0f, isKeyPressed);
		break;
	case SDL_SCANCODE_S:
		emulator->UpdateInput(0x0b, isKeyPressed);
		break;
	case SDL_SCANCODE_A:
		emulator->UpdateInput(0x0a, isKeyPressed);
		break;
	}
}




