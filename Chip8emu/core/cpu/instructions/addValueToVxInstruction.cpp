/*
 * addValueToVxInstruction.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: Tomas Stibrany
 */
#include "addValueToVxInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

AddValueToVxInstruction::AddValueToVxInstruction(u8 registerIndex, u8 value, CPU *cpu) : IInstruction()
{
	this->registerIndex = registerIndex;
	this->value = value;
	this->cpu = cpu;
}

AddValueToVxInstruction::~AddValueToVxInstruction()
{
}

void AddValueToVxInstruction::Execute()
{
	u8 currentValue = cpu->ReadFromGeneralPurposeRegister(registerIndex);
	u8 newValue = currentValue + value;
	cpu->WriteToGeneralPurposeRegister(registerIndex, newValue);
}



