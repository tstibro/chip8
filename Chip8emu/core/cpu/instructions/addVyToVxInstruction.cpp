/*
 * addVyToVxInstruction.cpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */
#include "addVyToVxInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

AddVyToVxInstruction::AddVyToVxInstruction(u8 registerYindex, u8 registerXindex, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	SetRegisterYindex(registerYindex);
	this->cpu = cpu;
}

AddVyToVxInstruction::~AddVyToVxInstruction()
{
}

void AddVyToVxInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(registerXindex);
	u8 registerYvalue = this->cpu->ReadFromGeneralPurposeRegister(registerYindex);
	this->cpu->WriteToGeneralPurposeRegister(registerXindex, registerXvalue + registerYvalue);
	//VF is set to 1 when there's a carry, and to 0 when there isn't.
	u8 carry = (registerXvalue + registerYvalue > 255);
	this->cpu->WriteToFlagRegister(carry);
}

void AddVyToVxInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}

void AddVyToVxInstruction::SetRegisterYindex(u8 registerIndex)
{
	this->registerYindex = registerIndex;
}




