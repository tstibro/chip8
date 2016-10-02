/*
 * setVxToVxAndVyInstruction.cpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */
#include "setVxToVxAndVyInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SetVxToVxAndVyInstruction::SetVxToVxAndVyInstruction(u8 registerXindex, u8 registerYindex, CPU *cpu)
{
	this->registerXindex = registerXindex;
	this->registerYindex = registerYindex;
	this->cpu = cpu;
}

SetVxToVxAndVyInstruction::~SetVxToVxAndVyInstruction()
{
}

void SetVxToVxAndVyInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(registerXindex);
	u8 registerYvalue = this->cpu->ReadFromGeneralPurposeRegister(registerYindex);
	this->cpu->WriteToGeneralPurposeRegister(registerXindex, registerXvalue & registerYvalue);
}


