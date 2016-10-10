/*
 * chip8emulator.hpp
 *
 *  Created on: Aug 7, 2016
 *      Author: Tomas Stibrany
 */

#ifndef EMULATOR_CHIP8EMULATOR_HPP_
#define EMULATOR_CHIP8EMULATOR_HPP_
#include <time.h>

namespace chip8 { namespace core { namespace memory
{
	class RAM;
}}}

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace io { namespace output
{
	class Display;
}}}

namespace chip8 { namespace io { namespace input
{
	class Keyboard;
}}}

namespace chip8 { namespace font
{
	class Font;
}}

using namespace chip8::core::memory;
using namespace chip8::core::cpu;
using namespace chip8::io::output;
using namespace chip8::io::input;
using namespace chip8::font;

namespace chip8
{

	class Chip8
	{
	private:
		RAM *ram;
		CPU *cpu;
		Keyboard *keyboard;
		Display *display;
		Font *font;
		clock_t lastTick;
		bool romLoaded;

		void initialize();
		void tick(); // Run the clock
	public:
		Chip8();
		~Chip8();

		void CreateWindow(char *windowTitle);
		void LoadROM(char *filePath);
		void EmulateCycle();
	};
}

#endif /* EMULATOR_CHIP8EMULATOR_HPP_ */
