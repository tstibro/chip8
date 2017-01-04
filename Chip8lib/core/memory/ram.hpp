/*
 * ram.hpp
 *
 *  Created on: Jul 4, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_MEMORY_RAM_HPP_
#define CORE_MEMORY_RAM_HPP_
#include "../../chip8Types.hpp"

#define RAM_DEFAULT_SIZE 4096
#define RAM_PROGRAM_SPACE_START 512
#define RAM_DISPLAY_REFRESH_SIZE 256
#define RAM_INTERNAL_USE_SIZE 96

namespace chip8 { namespace core { namespace memory
{

	class RAM
	{
	private:
		u16 memorySize;
		u8 *memory;
		// Initializes memory space
		void createMemorySpace();
		// Prevents access to memory address higher than memorySize
		uint16_t getSafeAddress(u16 address);

	public:
		// Default constructor. Initializes RAM with 4096 bytes of memory.
		RAM();
		// Constructor. Allows initialization with custom amount of memory.
		RAM(u16 numberOfBytes);
		// Destructor.
		~RAM();
		// Write byte to memory address
		void Write(u16 address, u8 value);
		// Read byte from memory address
		u8 Read(u16 address);
		// Returns size allocated memory space
		u16 GetMemorySize();
		// Returns address where program data starts
		u16 GetProgramSegmentStartAddress();
		// Returns address where program data ends
		u16 GetProgramSegmentEndAddress();
		// Returns address where display refresh data starts
		u16 GetDisplayRefreshStartAddress();
		// Returns address where display refresh data ends
		u16 GetDisplayRefreshEndAddress();
		// Returns start address reserved for internal use. (call stack, other variables, ...)
		u16 GetReservedSegmentStartAddress();
		// Returns end address reserved for internal use. (call stack, other variables, ...)
		u16 GetReservedSegmentEndAddress();
		// Returns start address where font data is located
		u16 GetFontDataStartAddress();
		// Returns end address where font data is located
		u16 GetFontDataEndAddress();
	};

}}}

#endif /* CORE_MEMORY_RAM_HPP_ */
