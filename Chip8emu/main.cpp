/*
 * chip8.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: Tomas Stibrany
 */
#include "chip8emulator.hpp"

using namespace chip8;

int main(int argc, char **argv)
{
	Chip8 *emulator = new Chip8();

 	if(argc > 1)
	{
		emulator->CreateWindow("Chip8 Emulator");
 		emulator->LoadROM(argv[1]);

		bool isRunning = true;
		while (isRunning)
		{
 			emulator->EmulateCycle();
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




