/*
 * setVxToValueOfDelayTimerInstruction.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */
#include "setVxToValueOfDelayTimerInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SetVxToValueOfDelayTimerInstruction::SetVxToValueOfDelayTimerInstruction(u8 registerXindex, CPU *cpu) : IInstruction()
{
	this->registerXindex = registerXindex;
	this->cpu = cpu;
}

SetVxToValueOfDelayTimerInstruction::~SetVxToValueOfDelayTimerInstruction()
{
}

void SetVxToValueOfDelayTimerInstruction::Execute()
{
	u8 delayTimerValue = this->cpu->GetDelayTimerValue();
	this->cpu->WriteToGeneralPurposeRegister(this->registerXindex, delayTimerValue);
}



