/*
 * clearScreenInstruction.cpp
 *
 *  Created on: Aug 1, 2016
 *      Author: Tomas Stibrany
 */
#include "clearScreenInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

ClearScreenInstruction::ClearScreenInstruction(CPU *cpu) : IInstruction()
{
	this->cpu = cpu;
}

ClearScreenInstruction::~ClearScreenInstruction()
{
}

void ClearScreenInstruction::Execute()
{
	this->cpu->ClearScreen();
}



