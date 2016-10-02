/*
 * setAddressRegisterValueInstruction.cpp
 *
 *  Created on: Jul 13, 2016
 *      Author: Tomas Stibrany
 */
#include "setIndexRegisterValueInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SetIndexRegisterValueInstruction::SetIndexRegisterValueInstruction(u16 value, CPU *cpu)  :IInstruction()
{
	this->cpu = cpu;
	this->value = value;
}

SetIndexRegisterValueInstruction::~SetIndexRegisterValueInstruction()
{
}

void SetIndexRegisterValueInstruction::Execute()
{
	this->cpu->WriteToIndexRegister(value);
}




