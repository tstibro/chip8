/*
 * setSoundTimerToVxInstruction.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */
#include "setSoundTimerToVxInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SetSoundTimerToVxInstruction::SetSoundTimerToVxInstruction(u8 registerXindex, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	this->cpu = cpu;
}

SetSoundTimerToVxInstruction::~SetSoundTimerToVxInstruction()
{
}

void SetSoundTimerToVxInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(this->registerXindex);
	this->cpu->SetSoundTimerValue(registerXvalue);
}

void SetSoundTimerToVxInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}



