/*
 * waitForKeyPressInstruction.cpp
 *
 *  Created on: Jul 30, 2016
 *      Author: Tomas Stibrany
 */
#include "waitForKeyPressInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

WaitForKeyPressInstruction::WaitForKeyPressInstruction(u8 registerXindex, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	this->cpu = cpu;
}

WaitForKeyPressInstruction::~WaitForKeyPressInstruction()
{
}

void WaitForKeyPressInstruction::Execute()
{
	if (!this->cpu->isAnyKeyPressed())
	{
		this->cpu->RepeatInstruction();
	}
	else
	{
		u8 pressedKey = this->cpu->GetLastPressedKey();
		this->cpu->WriteToGeneralPurposeRegister(this->registerXindex, pressedKey);
	}
}

void WaitForKeyPressInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}



