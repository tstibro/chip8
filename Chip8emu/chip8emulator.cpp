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

	lastTick = 0;
}

void Chip8::tick()
{
	double currentMilliseconds = (double)clock() / ((double)CLOCKS_PER_SEC / 1000.0);

	if (lastTick == 0)
		lastTick = (clock_t)currentMilliseconds;
	else if (currentMilliseconds - (double)lastTick > 1.0)
	{
		this->cpu->TimerTick();
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
		double milliseconds = (double)clock() / ((double)CLOCKS_PER_SEC / 1000.0);

		while (isRunning)
		{
			while (SDL_PollEvent(&event) > 0)
			{
				if (event.type == SDL_QUIT)
				{
					isRunning = false;
					break;
				}
			}

			double currentMilliseconds = (double)clock() / ((double)CLOCKS_PER_SEC / 1000.0);
			if (currentMilliseconds - milliseconds > (1000.0 / EMULATOR_FREQ))
			{
				cpu->ExecuteInstruction();
			}

			display->Refresh();			
			tick();
			milliseconds = currentMilliseconds;
		}
	}
}

