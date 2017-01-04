/*
 * storeBCDvalueOfVxInsrtruction.cpp
 *
 *  Created on: Jul 23, 2016
 *      Author: Tomas Stibrany
 */
#include "storeBCDvalueOfVxInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

StoreBCDvalueOfVxInstruction::StoreBCDvalueOfVxInstruction(u8 registerXindex, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(registerXindex);
	this->cpu = cpu;
}

StoreBCDvalueOfVxInstruction::~StoreBCDvalueOfVxInstruction()
{
}

void StoreBCDvalueOfVxInstruction::Execute()
{
	u8 registerXvalue = this->cpu->ReadFromGeneralPurposeRegister(this->registerXindex);
	// Calculate BCD
	u8 bcdHundreds = registerXvalue / 100;
	u8 bcdTens = (registerXvalue - (bcdHundreds * 100)) / 10;
	u8 bcdOnes = (registerXvalue - (bcdHundreds * 100) - (bcdTens * 10));
	// Store BCD
	u16 address = this->cpu->ReadFromIndexRegister();
	this->cpu->WriteToMemory(bcdHundreds);

	this->cpu->WriteToIndexRegister(address + 1);
	this->cpu->WriteToMemory(bcdTens);

	this->cpu->WriteToIndexRegister(address + 2);
	this->cpu->WriteToMemory(bcdOnes);
	// Restore Index register
	this->cpu->WriteToIndexRegister(address);
}

void StoreBCDvalueOfVxInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->registerXindex = registerIndex;
}


