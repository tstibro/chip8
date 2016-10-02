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
	this->registerXindex = registerXindex;
	this->cpu = cpu;
}

WaitForKeyPressInstruction::~WaitForKeyPressInstruction()
{
}

void WaitForKeyPressInstruction::Execute()
{
	u8 pressedKey;
	while((pressedKey = this->cpu->GetPressedKey()) == -1)
	{
	}
	this->cpu->WriteToGeneralPurposeRegister(this->registerXindex, pressedKey);
}



