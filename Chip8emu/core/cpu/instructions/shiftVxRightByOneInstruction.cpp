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

ShiftVxRightInstruction::ShiftVxRightInstruction(u8 registerXindex, u8 registerYindex,CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	SetRegisterYindex(registerYindex);
	this->cpu = cpu;
}

ShiftVxRightInstruction::~ShiftVxRightInstruction()
{
}

void ShiftVxRightInstruction::Execute()
{
	u8 currentValue = this->cpu->ReadFromGeneralPurposeRegister(registerXindex);
	u8 numberOfBitsToShift = this->cpu->ReadFromGeneralPurposeRegister(registerYindex);
	u8 newValue = (currentValue >> numberOfBitsToShift);
	this->cpu->WriteToGeneralPurposeRegister(registerXindex, newValue);
	//VF is set to the value of the least significant bit of VX before the shift.
	this->cpu->WriteToFlagRegister(currentValue & 0x1);
}

void ShiftVxRightInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}

void ShiftVxRightInstruction::SetRegisterYindex(u8 registerIndex)
{
	this->registerYindex = registerIndex;
}



