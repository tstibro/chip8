/*
 * chip8emulator.cpp
 *
 *  Created on: Aug 7, 2016
 *      Author: Tomas Stibrany
 */
#include "chip8emulator.hpp"
#include <iostream>
#include <fstream>
#include <SDL.h>

#include "chip8Types.hpp"
#include "core/cpu/cpu.hpp"
#include "core/memory/ram.hpp"
#include "core/memory/programLoader.hpp"
#include "font/fontLoader.hpp"
#include "font/font.hpp"
#include "keyboard/keyboard.hpp"
#include "display/display.hpp"

using namespace std;
using namespace chip8::core::cpu;
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
	delete ram;
	delete cpu;
}

void Chip8::initialize()
{
	keyboard = new Keyboard();
	display = new Display();

	ram = new RAM();
	FontLoader fontLoader;
	font = new Font();
	fontLoader.LoadTo(ram, font);

	cpu = new CPU(ram, display, keyboard);
}

void Chip8::tick(long long dt)
{
	while (dt > 0)
	{
		this->cpu->TimerTick();
		dt -= 1;
	}
}

void Chip8::CreateWindow(char *windowTitle)
{
	display->CreateWindow(windowTitle);
	display->ClearScreen();
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
		SDL_Event event;
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
					while (SDL_PollEvent(&event) > 0)
					{
						if (event.type == SDL_QUIT)
						{
							isRunning = false;
							break;
						}
					}
				}
				tick(timeDelta);
			}
		    display->Refresh();
			cpu->ExecuteInstruction();
		}
	}
}

