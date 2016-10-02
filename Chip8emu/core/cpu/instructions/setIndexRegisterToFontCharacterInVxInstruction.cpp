/*
 * setAddressRegisterToFontCharacterInVxInstruction.cpp
 *
 *  Created on: Jul 25, 2016
 *      Author: Tomas Stibrany
 */
#include "setIndexRegisterToFontCharacterInVxInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

SetIndexRegisterToFontCharacterInVxInstruction::SetIndexRegisterToFontCharacterInVxInstruction(u8 registerXindex, CPU *cpu) : IInstruction()
{
	this->registerXindex = registerXindex;
	this->cpu = cpu;
}

SetIndexRegisterToFontCharacterInVxInstruction::~SetIndexRegisterToFontCharacterInVxInstruction()
{
}

void SetIndexRegisterToFontCharacterInVxInstruction::Execute()
{
	u8 fontCharacterIndex = this->cpu->ReadFromGeneralPurposeRegister(this->registerXindex);
	u16 fontCharacterAddress = this->cpu->GetFontDataStartAddress() + (fontCharacterIndex * 5); // 5 bytes per character. Note: refactor this constant.
	this->cpu->WriteToIndexRegister(fontCharacterAddress);
}


