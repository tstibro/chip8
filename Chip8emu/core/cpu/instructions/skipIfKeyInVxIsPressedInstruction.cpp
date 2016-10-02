/*
 * skipIfKeyInVxIsPressedInstruction.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: Tomas Stibrany
 */
#include "skipIfKeyInVxIsPressedInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SkipIfKeyInVxIsPressedInstruction::SkipIfKeyInVxIsPressedInstruction(u8 registerXindex, CPU *cpu) : IInstruction()
{
	this->registerXindex = registerXindex;
	this->cpu = cpu;
}

SkipIfKeyInVxIsPressedInstruction::~SkipIfKeyInVxIsPressedInstruction()
{
}

void SkipIfKeyInVxIsPressedInstruction::Execute()
{
	u8 targetKeyCode = this->cpu->ReadFromGeneralPurposeRegister(this->registerXindex);
	u8 pressedKeyCode = this->cpu->GetPressedKey();

	if (targetKeyCode == pressedKeyCode)
	{
		this->cpu->SkipNextInstruction();
	}
}



