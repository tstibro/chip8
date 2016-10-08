/*
 * setVxToRandomValueBitwiseAndValueInstruction.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */
#include "setVxToRandomValueBitwiseAndValueInstruction.hpp"
#include "../cpu.hpp"
#include <stdlib.h>

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SetVxToRandomValueBitwiseAndValueInstruction::SetVxToRandomValueBitwiseAndValueInstruction(u8 registerXindex, u8 value, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	SetValue(value);
	this->cpu = cpu;
}

SetVxToRandomValueBitwiseAndValueInstruction::~SetVxToRandomValueBitwiseAndValueInstruction()
{
}

void SetVxToRandomValueBitwiseAndValueInstruction::Execute()
{
	u8 newValue = ((u8)std::rand()) & value;
	this->cpu->WriteToGeneralPurposeRegister(registerXindex, newValue);
}

void SetVxToRandomValueBitwiseAndValueInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}

void SetVxToRandomValueBitwiseAndValueInstruction::SetValue(u8 value)
{
	this->value = value;
}




