/*
 * setDelayTimerToVxInstruction.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */
#include "setDelayTimerToVxInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SetDelayTimerToVxInstruction::SetDelayTimerToVxInstruction(u8 registerXindex, CPU *cpu) : IInstruction()
{
	this->registerXindex = registerXindex;
	this->cpu = cpu;
}

SetDelayTimerToVxInstruction::~SetDelayTimerToVxInstruction()
{
}

void SetDelayTimerToVxInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(this->registerXindex);
	this->cpu->SetDelayTimerValue(registerXvalue);
}



