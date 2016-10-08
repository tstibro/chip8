/*
 * callInstruction.cpp
 *
 *  Created on: Jul 21, 2016
 *      Author: Tomas Stibrany
 */
#include "callInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

CallInstruction::CallInstruction(u16 address, CPU *cpu) : IInstruction()
{
	SetAddress(address);
	this->cpu = cpu;
}

CallInstruction::~CallInstruction()
{
}

void CallInstruction::Execute()
{
	this->cpu->SaveReturnAddress();
	this->cpu->JumpToAddress(this->address);
}

void CallInstruction::SetAddress(u16 address)
{
	this->address = address;
}



