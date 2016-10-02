/*
 * addVxToAddressRegisterInstruction.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */
#include "addVxToIndexRegisterInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

AddVxToIndexRegisterInstruction::AddVxToIndexRegisterInstruction(u8 registerXindex, CPU *cpu) : IInstruction()
{
	this->registerXindex = registerXindex;
	this->cpu = cpu;
}

AddVxToIndexRegisterInstruction::~AddVxToIndexRegisterInstruction()
{
}

void AddVxToIndexRegisterInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(this->registerXindex);
	u16 indexRegisterValue = this->cpu->ReadFromIndexRegister();
	u16 newValue = indexRegisterValue + registerXvalue;
	this->cpu->WriteToIndexRegister(newValue);
	// VF is set to 1 when range overflow (I+VX>0xFFF), and 0 when there isn't.
	this->cpu->WriteToFlagRegister(newValue > 0xFFF ? 1 : 0);
}



