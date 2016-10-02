/*
 * jumpToGivenAddressWithOffset.cpp
 *
 *  Created on: Jul 20, 2016
 *      Author: Tomas Stibrany
 */
#include "jumpToGivenAddressWithOffset.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

JumpToGivenAddressWithOffset::JumpToGivenAddressWithOffset(u16 address, CPU *cpu) : IInstruction()
{
	this->address = address;
	this->cpu = cpu;
}

JumpToGivenAddressWithOffset::~JumpToGivenAddressWithOffset()
{
}

void JumpToGivenAddressWithOffset::Execute()
{
	u8 registerV0index = 0;
	u8 offset = this->cpu->ReadFromGeneralPurposeRegister(registerV0index);
	u16 finalAddress = this->address + offset;
	this->cpu->JumpToAddress(finalAddress);
}



