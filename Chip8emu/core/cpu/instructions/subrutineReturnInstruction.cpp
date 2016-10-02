/*
 * subrutineReturnInstruction.cpp
 *
 *  Created on: Jul 21, 2016
 *      Author: Tomas Stibrany
 */
#include "subrutineReturnInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SubrutineReturnInstruction::SubrutineReturnInstruction(CPU *cpu) : IInstruction()
{
	this->cpu = cpu;
}

SubrutineReturnInstruction::~SubrutineReturnInstruction()
{
}

void SubrutineReturnInstruction::Execute()
{
	u16 returnAddress = this->cpu->LoadReturnAddress();
	this->cpu->JumpToAddress(returnAddress);
}

