/*
 * skipNextIfVxNotEqualsValueInstruction.cpp
 *
 *  Created on: Jul 18, 2016
 *      Author: Tomas Stibrany
 */
#include "skipNextIfVxNotEqualsValueInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SkipNextIfVxNotEqualsValueInstruction::SkipNextIfVxNotEqualsValueInstruction(u8 registerXindex, u8 value, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	SetValue(value);
	this->cpu = cpu;
}

SkipNextIfVxNotEqualsValueInstruction::~SkipNextIfVxNotEqualsValueInstruction()
{
}

void SkipNextIfVxNotEqualsValueInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(this->registerXindex);
	if (registerXvalue != this->value)
		this->cpu->SkipNextInstruction();
}

void SkipNextIfVxNotEqualsValueInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}

void SkipNextIfVxNotEqualsValueInstruction::SetValue(u8 value)
{
	this->value = value;
}



