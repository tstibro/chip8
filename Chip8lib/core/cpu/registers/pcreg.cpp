/*
* gpr.cpp
*
*  Created on: September 29, 2016
*      Author: Tomas Stibrany
*/
#include "pcreg.hpp"
using namespace chip8::core::cpu::registers;

ProgramCounterRegister::ProgramCounterRegister(u16 resetAddress)
{
	registerContents = resetAddress;
	Unlock();
}

ProgramCounterRegister::~ProgramCounterRegister()
{
}

void ProgramCounterRegister::Lock()
{
	locked = true;
}

void ProgramCounterRegister::Unlock()
{
	locked = false;
}

void ProgramCounterRegister::JumpToAddress(u16 address)
{
	if (!locked)
		registerContents = address;
}

void ProgramCounterRegister::SetNextInstruction()
{
	if (!locked)
		registerContents += 2;
}

u16 ProgramCounterRegister::Read()
{
	return registerContents;
}