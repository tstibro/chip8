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

Chip8::~Chip8()
{
	delete keyboard;
	delete display;
	delete ram;
	delete cpu;
}

void Chip8::LoadROM(char *filePath)
{
	ProgramLoader programLoader;
	programLoader.LoadTo(ram, filePath);
	romLoaded = true;
}

void Chip8::Run()
{
	if (romLoaded)
	{
		display->CreateWindow("Chip8 Emulator");
		display->ClearScreen();

		SDL_Event event;
		/*u8 spriteData[5] = {0xf0,0x10,0xf0,0x10,0xf0};
		int x = 0;
		int y = 0;*/
		while (1)
		{
			SDL_WaitEvent(&event);
			if (event.type == SDL_QUIT)
			{
				break;
			}

			cpu->ExecuteInstruction();
			//display->Draw(spriteData, 1, 5, x++ % 64, y++ % 32);
			display->Refresh();
		}
	}
}

