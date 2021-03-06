/*
 * jumpInstruction.cpp
 *
 *  Created on: Jul 21, 2016
 *      Author: Tomas Stibrany
 */
#include "jumpInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

JumpInstruction::JumpInstruction(u16 address, CPU *cpu) : IInstruction()
{
	SetAddress(address);
	this->cpu = cpu;
}

JumpInstruction::~JumpInstruction()
{
}

void JumpInstruction::Execute()
{
	this->cpu->JumpToAddress(this->address);
}

void JumpInstruction::SetAddress(u16 address)
{
	this->address = address;
}



