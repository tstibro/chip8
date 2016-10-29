/*
 * subtractVyFromVxInstruction.cpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */
#include "subtractVyFromVxInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SubtractVyFromVxInstruction::SubtractVyFromVxInstruction(u8 registerYindex, u8 registerXindex, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	SetRegisterYindex(registerYindex);
	this->cpu = cpu;
}

SubtractVyFromVxInstruction::~SubtractVyFromVxInstruction()
{
}

void SubtractVyFromVxInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(registerXindex);
	u8 registerYvalue = this->cpu->ReadFromGeneralPurposeRegister(registerYindex);
	u8 newValue = (u8)((i16)registerXvalue - (i16)registerYvalue);
	this->cpu->WriteToGeneralPurposeRegister(registerXindex, newValue);
	// VF is set to 0 when there's a borrow, and 1 when there isn't.
	u8 borrowFlag = (registerXvalue >= registerYvalue) ? 1 : 0;
	this->cpu->WriteToFlagRegister(borrowFlag);
}

void SubtractVyFromVxInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}

void SubtractVyFromVxInstruction::SetRegisterYindex(u8 registerIndex)
{
	this->registerYindex = registerIndex;
}
