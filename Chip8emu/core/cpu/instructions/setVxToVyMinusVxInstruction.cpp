/*
 * setVxToVyMinusVxInstruction.cpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */
#include "setVxToVyMinusVxInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SetVxToVyMinusVxInstruction::SetVxToVyMinusVxInstruction(u8 registerXindex, u8 registerYindex, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	SetRegisterYindex(registerYindex);
	this->cpu = cpu;
}

SetVxToVyMinusVxInstruction::~SetVxToVyMinusVxInstruction()
{
}

void SetVxToVyMinusVxInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(registerXindex);
	u8 registerYvalue = this->cpu->ReadFromGeneralPurposeRegister(registerYindex);
	u8 newValue = registerYvalue - registerXvalue;
	this->cpu->WriteToGeneralPurposeRegister(registerXindex, newValue);
	//VF is set to 0 when there's a borrow, and 1 when there isn't.
	u8 borrow = (registerYvalue > registerXvalue);
	this->cpu->WriteToFlagRegister(borrow);
}

void SetVxToVyMinusVxInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}

void SetVxToVyMinusVxInstruction::SetRegisterYindex(u8 registerIndex)
{
	this->registerYindex = registerIndex;
}




