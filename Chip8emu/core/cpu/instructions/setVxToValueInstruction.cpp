/*
 * SetVxToValueInstruction.cpp
 *
 *  Created on: Jul 9, 2016
 *      Author: Tomas Stibrany
 */
#include "setVxToValueInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SetVxToValueInstruction::SetVxToValueInstruction(u8 gprIndex,u8 value,CPU *cpu) : IInstruction()
{
	SetRegisterXindex(gprIndex);
	SetValue(value);
	this->cpu = cpu;
}

SetVxToValueInstruction::~SetVxToValueInstruction()
{
}

void SetVxToValueInstruction::Execute()
{
	this->cpu->WriteToGeneralPurposeRegister(gprIndex, value);
}

void SetVxToValueInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->gprIndex = registerIndex;
}

void SetVxToValueInstruction::SetValue(u8 value)
{
	this->value = value;
}
