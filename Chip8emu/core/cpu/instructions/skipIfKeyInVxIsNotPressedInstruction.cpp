/*
 * skipIfKeyInVxIsNotPressedInstruction.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: Tomas Stibrany
 */
#include "skipIfKeyInVxIsNotPressedInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SkipIfKeyInVxIsNotPressedInstruction::SkipIfKeyInVxIsNotPressedInstruction(u8 registerXindex, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	this->cpu = cpu;
}

SkipIfKeyInVxIsNotPressedInstruction::~SkipIfKeyInVxIsNotPressedInstruction()
{
}

void SkipIfKeyInVxIsNotPressedInstruction::Execute()
{
	u8 targetKeyCode = this->cpu->ReadFromGeneralPurposeRegister(this->registerXindex);

	if (!this->cpu->isKeyPressed(targetKeyCode))
	{
		this->cpu->SkipNextInstruction();
	}
}

void SkipIfKeyInVxIsNotPressedInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}




