/*
 * fillV0toVxWithValueFromMemoryInstruction.cpp
 *
 *  Created on: Jul 19, 2016
 *      Author: Tomas Stibrany
 */
#include "fillV0toVxWithValueFromMemoryInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

FillV0toVxWithValueFromMemoryInstruction::FillV0toVxWithValueFromMemoryInstruction(u8 registerXindex, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	this->cpu = cpu;
}

FillV0toVxWithValueFromMemoryInstruction::~FillV0toVxWithValueFromMemoryInstruction()
{
}

void FillV0toVxWithValueFromMemoryInstruction::Execute()
{
	u16 ramAddress = this->cpu->ReadFromIndexRegister();
	for(u8 currentRegisterIndex = 0; currentRegisterIndex <= this->registerXindex; currentRegisterIndex++)
	{
		this->cpu->WriteToIndexRegister(ramAddress + currentRegisterIndex);
		u8 newRegisterValue = this->cpu->ReadFromMemory();
		this->cpu->WriteToGeneralPurposeRegister(currentRegisterIndex, newRegisterValue);
	}
	this->cpu->WriteToIndexRegister(ramAddress + this->registerXindex + 1);
}

void FillV0toVxWithValueFromMemoryInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}



