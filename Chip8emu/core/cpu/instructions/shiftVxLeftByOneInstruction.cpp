/*
 * shiftVxLeftByOneInstruction.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */
#include "shiftVxLeftByOneInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

ShiftVxLeftInstruction::ShiftVxLeftInstruction(u8 registerXindex, u8 registerYindex,CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	SetRegisterYindex(registerYindex);
	this->cpu = cpu;
}

ShiftVxLeftInstruction::~ShiftVxLeftInstruction()
{
}

void ShiftVxLeftInstruction::Execute()
{
	u8 currentValue = this->cpu->ReadFromGeneralPurposeRegister(registerXindex);
	u8 numberOfBitsToShift = this->cpu->ReadFromGeneralPurposeRegister(registerYindex);
	u8 newValue = (currentValue << numberOfBitsToShift);
	this->cpu->WriteToGeneralPurposeRegister(registerXindex, newValue);
	//VF is set to the value of the most significant bit of VX before the shift.
	this->cpu->WriteToFlagRegister((currentValue >> 7) & 0x1);
}

void ShiftVxLeftInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}

void ShiftVxLeftInstruction::SetRegisterYindex(u8 registerIndex)
{
	this->registerYindex = registerIndex;
}


