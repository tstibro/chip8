/*
 * cpu.hpp
 *
 *  Created on: Jul 4, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_CPU_HPP_
#define CORE_CPU_CPU_HPP_

#include <stack>
#include "timers/timer.hpp"
#include "registers/gpr.hpp"
#include "registers/ri.hpp"
#include "registers/pcreg.hpp"

#define GPR_COUNT 16

namespace chip8 { namespace core { namespace memory
{
	class RAM;
}}}

namespace chip8 { namespace io { namespace output
{
	class Display;
}}}

namespace chip8 { namespace io { namespace input
{
	class Keyboard;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{
	class IInstruction;
	class InstructionFactory;
}}}}

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu::registers;
using namespace chip8::core::cpu::timers;
using namespace chip8::core::memory;
using namespace chip8::io::output;
using namespace chip8::io::input;
using namespace std;

namespace chip8 { namespace core { namespace cpu
{
	class CPU
	{
	private:
		RAM *ramMemory;
		stack<u16> stack;
		Timer delayTimer;
		Timer soundTimer;
		GeneralPurposeRegister generalPurposeRegister[GPR_COUNT];
		IndexRegister indexRegister;
		ProgramCounterRegister *programCounter;
		InstructionFactory *instructionFactory;

		Keyboard *keyboard;
		Display *display;

		u16 loadInstruction();
		void setNextInstruction();
	public:
		// Default constructor
		CPU(RAM *ramMemory, Display *display, Keyboard *keyboard);
		// Destructor
		~CPU();
		// Loads and Executes instruction
		void ExecuteInstruction();
		// Skip instruction by incrementing PC
		void SkipNextInstruction();
		// Moves flow control to given address. Address is validated.
		void JumpToAddress(u16 address);
		// Saves address PC+2 to Stack
		void SaveReturnAddress();
		// Loads return address from Stack;
		u16 LoadReturnAddress();

		void WriteToGeneralPurposeRegister(u8 registerIndex, u8 value);
		u8 ReadFromGeneralPurposeRegister(u8 registerIndex);
		void WriteToFlagRegister(u8 value);
		u8 ReadFlagRegister();
		void WriteToIndexRegister(u16 value);
		u16 ReadFromIndexRegister();

		// Writes to RAM at address stored in indexRegister
		void WriteToMemory(u8 value);
		// Reads from RAM address stored in indexRegister
		u8 ReadFromMemory();
		// Return Memory address where Font data start. Note: Refactor into memory layout or something
		u16 GetFontDataStartAddress();

		void SetDelayTimerValue(u8 value);
		u8 GetDelayTimerValue();
		void SetSoundTimerValue(u8 value);

		// Returns pressed key on keyboard, or -1 when no key is pressed
		u8 GetPressedKey();

		void ClearScreen();
		u8 DrawSprite(u8 *spriteData, u8 spriteWidth, u8 spriteHeight, u8 x, u8 y);
	};

}}}




#endif /* CORE_CPU_CPU_HPP_ */
