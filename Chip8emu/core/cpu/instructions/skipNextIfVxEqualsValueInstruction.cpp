/*
 * skipNextIfVxEqualsValueInstruction.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */
#include "skipNextIfVxEqualsValueInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SkipNextIfVxEqualsValueInstruction::SkipNextIfVxEqualsValueInstruction(u8 registerXindex, u8 value, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	SetValue(value);
	this->cpu = cpu;
}

SkipNextIfVxEqualsValueInstruction::~SkipNextIfVxEqualsValueInstruction()
{
}

void SkipNextIfVxEqualsValueInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(this->registerXindex);
	if (registerXvalue == value)
		this->cpu->SkipNextInstruction();
}

void SkipNextIfVxEqualsValueInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}

void SkipNextIfVxEqualsValueInstruction::SetValue(u8 value)
{
	this->value = value;
}



