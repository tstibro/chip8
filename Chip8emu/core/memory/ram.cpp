/*
 * ram.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: Tomas Stibrany
 */
#include "../memory/ram.hpp"
using namespace chip8::core::memory;

RAM::RAM()
{
	this->memorySize = RAM_DEFAULT_SIZE;
	createMemorySpace();
}

RAM::RAM(u16 numberOfBytes)
{
	this->memorySize = numberOfBytes;
	createMemorySpace();
}

RAM::~RAM()
{
	delete this->memory;
}

void RAM::createMemorySpace()
{
	this->memory = new u8[this->memorySize];
}

void RAM::Write(u16 address, u8 value)
{
	u16 safeAddress = getSafeAddress(address);
	this->memory[safeAddress] = value;
}

u8 RAM::Read(uint16_t address)
{
	u16 safeAddress = getSafeAddress(address);
	return this->memory[safeAddress];
}

u16 RAM::GetMemorySize()
{
	return this->memorySize;
}

u16 RAM::GetProgramSegmentStartAddress()
{
	return RAM_PROGRAM_SPACE_START;
}

u16 RAM::GetProgramSegmentEndAddress()
{
	return (GetReservedSegmentStartAddress() - 1);
}

u16 RAM::GetDisplayRefreshStartAddress()
{
	return (GetMemorySize() - RAM_DISPLAY_REFRESH_SIZE);
}

u16 RAM::GetDisplayRefreshEndAddress()
{
	return GetMemorySize() - 1;
}

u16 RAM::GetReservedSegmentStartAddress()
{
	return (GetDisplayRefreshStartAddress() - RAM_INTERNAL_USE_SIZE);
}

u16 RAM::GetReservedSegmentEndAddress()
{
	return (GetDisplayRefreshStartAddress() - 1);
}

u16 RAM::GetFontDataStartAddress()
{
	return 0;
}

u16 RAM::GetFontDataEndAddress()
{
	return (GetProgramSegmentStartAddress() - 1);
}

u16 RAM::getSafeAddress(u16 address)
{
	return (address % this->memorySize);
}
