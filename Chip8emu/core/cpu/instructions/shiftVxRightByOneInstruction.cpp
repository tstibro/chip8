/*
 * shiftVxRightByOneInstruction.cpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */
#include "shiftVxRightByOneInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

ShiftVxRightByOneInstruction::ShiftVxRightByOneInstruction(u8 registerXindex, CPU *cpu) : IInstruction()
{
	this->registerXindex = registerXindex;
	this->cpu = cpu;
}

ShiftVxRightByOneInstruction::~ShiftVxRightByOneInstruction()
{
}

void ShiftVxRightByOneInstruction::Execute()
{
	u8 currentValue = this->cpu->ReadFromGeneralPurposeRegister(registerXindex);
	u8 newValue = (currentValue >> 1);
	this->cpu->WriteToGeneralPurposeRegister(registerXindex, newValue);
	//VF is set to the value of the least significant bit of VX before the shift.
	this->cpu->WriteToFlagRegister((currentValue >> 7) & 0x1);
}



