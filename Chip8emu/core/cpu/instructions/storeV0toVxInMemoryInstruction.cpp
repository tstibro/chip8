/*
 * storeV0toVxInMemoryInstruction.cpp
 *
 *  Created on: Jul 19, 2016
 *      Author: Tomas Stibrany
 */
#include "storeV0toVxInMemoryInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

StoreV0toVxInMemoryInstruction::StoreV0toVxInMemoryInstruction(u8 registerXindex, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	this->cpu = cpu;
}

StoreV0toVxInMemoryInstruction::~StoreV0toVxInMemoryInstruction()
{
}

void StoreV0toVxInMemoryInstruction::Execute()
{
	u16 ramAddress = this->cpu->ReadFromIndexRegister();
	for(u8 currentRegisterIndex = 0; currentRegisterIndex <= this->registerXindex; currentRegisterIndex++)
	{
		u8 registerValue = this->cpu->ReadFromGeneralPurposeRegister(currentRegisterIndex);
		this->cpu->WriteToIndexRegister(ramAddress + currentRegisterIndex);
		this->cpu->WriteToMemory(registerValue);
	}
}

void StoreV0toVxInMemoryInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}

