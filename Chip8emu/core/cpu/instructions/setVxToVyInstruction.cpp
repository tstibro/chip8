/*
 * setVxToVyInstruction.cpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */
#include "setVxToVyInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SetVxToVyInstruction::SetVxToVyInstruction(u8 registerXindex, u8 registerYindex, CPU *cpu) : IInstruction()
{
	this->registerXindex = registerXindex;
	this->registerYindex = registerYindex;
	this->cpu = cpu;
}

SetVxToVyInstruction::~SetVxToVyInstruction()
{
}

void SetVxToVyInstruction::Execute()
{
	u8 registerYvalue = this->cpu->ReadFromGeneralPurposeRegister(registerYindex);
	this->cpu->WriteToGeneralPurposeRegister(registerXindex, registerYvalue);
}




