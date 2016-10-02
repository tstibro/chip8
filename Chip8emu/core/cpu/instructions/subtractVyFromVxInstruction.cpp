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
	this->registerXindex = registerXindex;
	this->registerYindex = registerYindex;
	this->cpu = cpu;
}

SubtractVyFromVxInstruction::~SubtractVyFromVxInstruction()
{
}

void SubtractVyFromVxInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(registerXindex);
	u8 registerYvalue = this->cpu->ReadFromGeneralPurposeRegister(registerYindex);
	u8 newValue = registerXvalue - registerYvalue;
	this->cpu->WriteToGeneralPurposeRegister(registerXindex, newValue);
	// VF is set to 0 when there's a borrow, and 1 when there isn't.
	u8 borrowFlag = (u8)(registerXvalue > registerYvalue);
	this->cpu->WriteToFlagRegister(borrowFlag);
}
