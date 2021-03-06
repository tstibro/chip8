/*
 * setVxToVxXorVyInstruction.cpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */
#include "setVxToVxXorVyInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SetVxToVxXorVyInstruction::SetVxToVxXorVyInstruction(u8 registerXindex, u8 registerYindex, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	SetRegisterYindex(registerYindex);
	this->cpu = cpu;
}

SetVxToVxXorVyInstruction::~SetVxToVxXorVyInstruction()
{
}

void SetVxToVxXorVyInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(registerXindex);
	u8 registerYvalue = this->cpu->ReadFromGeneralPurposeRegister(registerYindex);
	this->cpu->WriteToGeneralPurposeRegister(registerXindex, registerXvalue ^ registerYvalue);
}

void SetVxToVxXorVyInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}

void SetVxToVxXorVyInstruction::SetRegisterYindex(u8 registerIndex)
{
	this->registerYindex = registerIndex;
}


