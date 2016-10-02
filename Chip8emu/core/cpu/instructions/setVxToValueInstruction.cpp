/*
 * SetVxToValueInstruction.cpp
 *
 *  Created on: Jul 9, 2016
 *      Author: Tomas Stibrany
 */
#include "setVxToValueInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SetVxToValueInstruction::SetVxToValueInstruction(u8 gprIndex,u8 value,CPU *cpu) : IInstruction()
{
	this->gprIndex = gprIndex;
	this->value = value;
	this->cpu = cpu;
}

SetVxToValueInstruction::~SetVxToValueInstruction()
{
}

void SetVxToValueInstruction::Execute()
{
	this->cpu->WriteToGeneralPurposeRegister(gprIndex, value);
}
