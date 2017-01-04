/*
 * skipNextIfVxNotEqualsVyInstruction.cpp
 *
 *  Created on: Jul 18, 2016
 *      Author: Tomas Stibrany
 */
#include "skipNextIfVxNotEqualsVyInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SkipNextIfVxNotEqualsVyInstruction::SkipNextIfVxNotEqualsVyInstruction(u8 registerXindex, u8 registerYindex, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	SetRegisterYindex(registerYindex);
	this->cpu = cpu;
}

SkipNextIfVxNotEqualsVyInstruction::~SkipNextIfVxNotEqualsVyInstruction()
{
}

void SkipNextIfVxNotEqualsVyInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(this->registerXindex);
	u8 registerYvalue = this->cpu->ReadFromGeneralPurposeRegister(this->registerYindex);
	if (registerXvalue != registerYvalue)
		this->cpu->SkipNextInstruction();
}

void SkipNextIfVxNotEqualsVyInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}

void SkipNextIfVxNotEqualsVyInstruction::SetRegisterYindex(u8 registerIndex)
{
	this->registerYindex = registerIndex;
}



