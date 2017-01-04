/*
 * setVxToVxOrVyInstruction.cpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */
#include "setVxToVxOrVyInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SetVxToVxOrVyInstruction::SetVxToVxOrVyInstruction(u8 registerXindex, u8 registerYindex, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	SetRegisterYindex(registerYindex);
	this->cpu = cpu;
}

SetVxToVxOrVyInstruction::~SetVxToVxOrVyInstruction()
{
}

void SetVxToVxOrVyInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(registerXindex);
	u8 registerYvalue = this->cpu->ReadFromGeneralPurposeRegister(registerYindex);
	this->cpu->WriteToGeneralPurposeRegister(registerXindex, registerXvalue | registerYvalue);
}

void SetVxToVxOrVyInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}

void SetVxToVxOrVyInstruction::SetRegisterYindex(u8 registerIndex)
{
	this->registerYindex = registerIndex;
}


