/*
 * drawSpriteInstruction.cpp
 *
 *  Created on: Aug 1, 2016
 *      Author: Tomas Stibrany
 */
#include "drawSpriteInstruction.hpp"
#include "../cpu.hpp"

using namespace chip8::core::cpu::instructions;
using namespace chip8::core::cpu;

DrawSpriteInstruction::DrawSpriteInstruction(u8 xCoordinateRegister, u8 yCoordinateRegister, u8 spriteHeight, CPU *cpu) : IInstruction()
{
	SetRegisterXindex(xCoordinateRegister);
	SetRegisterYindex(yCoordinateRegister);
	SetSpriteHeight(spriteHeight);
	this->cpu = cpu;
}

DrawSpriteInstruction::~DrawSpriteInstruction()
{
}

void DrawSpriteInstruction::Execute()
{
	u8 xCoordinate = this->cpu->ReadFromGeneralPurposeRegister(this->xCoordinateRegister);
	u8 yCoordinate = this->cpu->ReadFromGeneralPurposeRegister(this->yCoordinateRegister);
	// We will copy sprite data into this array
	u8 *spriteData = new u8[this->spriteHeight];
	// and we need to preserve Index register value, so we save it
	u16 currentIndexRegisterValue = this->cpu->ReadFromIndexRegister();
	for(u8 y = 0; y < this->spriteHeight; y++)
	{
		this->cpu->WriteToIndexRegister(currentIndexRegisterValue + y);
		spriteData[y] = this->cpu->ReadFromMemory();
	}
	// Reset Index register value
	this->cpu->WriteToIndexRegister(currentIndexRegisterValue);

	u8 screenPixelFlipped = this->cpu->DrawSprite(spriteData, 1, this->spriteHeight, xCoordinate, yCoordinate);
	this->cpu->WriteToFlagRegister(screenPixelFlipped);

	delete spriteData;
}

void DrawSpriteInstruction::SetRegisterXindex(u8 registerIndex)
{
	this->xCoordinateRegister = registerIndex;
}

void DrawSpriteInstruction::SetRegisterYindex(u8 registerIndex)
{
	this->yCoordinateRegister = registerIndex;
}

void DrawSpriteInstruction::SetSpriteHeight(u8 spriteHeight)
{
	this->spriteHeight = spriteHeight;
}



