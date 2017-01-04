#ifndef PCREG_HPP
#define PCREG_HPP

#include <iostream>
#include "../../../chip8Types.hpp"

namespace chip8 {
	namespace core {
		namespace cpu { namespace registers
		{
			class ProgramCounterRegister
			{
			private:
				u16 registerContents;
				bool locked;
			public:
				// Default constructor. Register is unlocked when created.
				ProgramCounterRegister(u16 resetAddress);
				// Destructor
				~ProgramCounterRegister();
				// Prevents register from changing it's contents.
				void Lock();
				// Allows changing register contents.
				void Unlock();
				// Sets register to given address.
				void JumpToAddress(u16 address);
				// Increments register address by 2 bytes. (Instruction is 2B long)
				void SetNextInstruction();
				// Read register value
				u16 Read();
			};

		}}
	}
}

#endif