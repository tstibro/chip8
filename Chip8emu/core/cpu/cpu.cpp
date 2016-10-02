/*
 * cpu.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: Tomas Stibrany
 */
#include "cpu.hpp"
#include "../memory/ram.hpp"
#include "instructions/iinstruction.hpp"
#include "../../keyboard/keyboard.hpp"
#include "../../display/display.hpp"

#include "instructions/setIndexRegisterValueInstruction.hpp"
#include "instructions/unknownInstruction.hpp"
#include "instructions/setVxToValueInstruction.hpp"
#include "instructions/addValueToVxInstruction.hpp"
#include "instructions/setVxToVyInstruction.hpp"
#include "instructions/setVxToVxOrVyInstruction.hpp"
#include "instructions/setVxToVxAndVyInstruction.hpp"
#include "instructions/setVxToVxXorVyInstruction.hpp"
#include "instructions/addVyToVxInstruction.hpp"
#include "instructions/subtractVyFromVxInstruction.hpp"
#include "instructions/setVxToVyMinusVxInstruction.hpp"
#include "instructions/shiftVxRightByOneInstruction.hpp"
#include "instructions/shiftVxLeftByOneInstruction.hpp"
#include "instructions/setVxToRandomValueBitwiseAndValueInstruction.hpp"
#include "instructions/setVxToValueOfDelayTimerInstruction.hpp"
#include "instructions/setDelayTimerToVxInstruction.hpp"
#include "instructions/setSoundTimerToVxInstruction.hpp"
#include "instructions/addVxToIndexRegisterInstruction.hpp"
#include "instructions/skipNextIfVxEqualsValueInstruction.hpp"
#include "instructions/skipNextIfVxNotEqualsValueInstruction.hpp"
#include "instructions/skipNextIfVxEqualsVyInstruction.hpp"
#include "instructions/skipNextIfVxNotEqualsVyInstruction.hpp"
#include "instructions/storeV0toVxInMemoryInstruction.hpp"
#include "instructions/fillV0toVxWithValueFromMemoryInstruction.hpp"
#include "instructions/jumpToGivenAddressWithOffset.hpp"
#include "instructions/jumpInstruction.hpp"
#include "instructions/callInstruction.hpp"
#include "instructions/subrutineReturnInstruction.hpp"
#include "instructions/storeBCDvalueOfVxInstruction.hpp"
#include "instructions/setIndexRegisterToFontCharacterInVxInstruction.hpp"
#include "instructions/waitForKeyPressInstruction.hpp"
#include "instructions/skipIfKeyInVxIsNotPressedInstruction.hpp"
#include "instructions/skipIfKeyInVxIsPressedInstruction.hpp"
#include "instructions/clearScreenInstruction.hpp"
#include "instructions/drawSpriteInstruction.hpp"

using chip8::core::cpu::CPU;
using namespace chip8::core::cpu::instructions;

CPU::CPU(RAM *ramMemory, Display *display, Keyboard *keyboard)
{
	this->ramMemory = ramMemory;
	this->display = display;
	this->keyboard = keyboard;
	// Lets set the starting address of programCounter right now
	this->programCounter = new ProgramCounterRegister(ramMemory->GetProgramSegmentStartAddress());
}


CPU::~CPU()
{
	// RAM is passed by reference. We should not deallocate it.
}

u16 CPU::loadInstruction()
{
	u8 upperByte = ramMemory->Read(programCounter->Read());
	u8 lowerByte = ramMemory->Read(programCounter->Read() + 1);
	u16 rawInstruction = (u16)((upperByte << 8) | lowerByte);
	return rawInstruction;
}

void CPU::ExecuteInstruction()
{
	u16 rawInstruction = loadInstruction();
	IInstruction *instruction = decodeInstruction(rawInstruction);
	programCounter->Unlock(); // Allow changes of program counter (Jump instruction, ...)
	instruction->Execute();
	delete instruction;

	setNextInstruction();
}

void CPU::SkipNextInstruction()
{
	setNextInstruction();
}

void CPU::setNextInstruction()
{
	programCounter->SetNextInstruction();
}

void CPU::JumpToAddress(u16 address)
{
	u16 programStartAddress = this->ramMemory->GetProgramSegmentStartAddress();
	u16 programEndAddress = this->ramMemory->GetProgramSegmentEndAddress();
	if (programStartAddress <= address && programEndAddress >= address)
	{
		programCounter->JumpToAddress(address);
		programCounter->Lock();
	}
}

void CPU::SaveReturnAddress()
{
	u16 returnAddress = programCounter->Read() + 2;
	this->stack.push(returnAddress);
}

u16 CPU::LoadReturnAddress()
{
	u16 address =  this->stack.top();
	this->stack.pop();
	return address;
}

void CPU::WriteToGeneralPurposeRegister(u8 registerIndex, u8 value)
{
	u8 safeRegisterIndex = (registerIndex % GPR_COUNT);
	// Program cannot write to last GPR register (Flag register).
	if (safeRegisterIndex < (GPR_COUNT - 1))
	{
		this->generalPurposeRegister[safeRegisterIndex].Write(value);
	}
}

u8 CPU::ReadFromGeneralPurposeRegister(u8 registerIndex)
{
	u8 safeRegisterIndex = (registerIndex % GPR_COUNT);
	return this->generalPurposeRegister[safeRegisterIndex].Read();
}

void CPU::WriteToFlagRegister(u8 value)
{
	this->generalPurposeRegister[GPR_COUNT - 1].Write(value);
}

u8 CPU::ReadFlagRegister()
{
	return this->generalPurposeRegister[GPR_COUNT - 1].Read();
}

void CPU::WriteToIndexRegister(u16 value)
{
	this->indexRegister.Write(value);
}

u16 CPU::ReadFromIndexRegister()
{
	return this->indexRegister.Read();
}

void CPU::WriteToMemory(u8 value)
{
	this->ramMemory->Write(this->indexRegister.Read(), value);
}

u8 CPU::ReadFromMemory()
{
	return this->ramMemory->Read(this->indexRegister.Read());
}

u16 CPU::GetFontDataStartAddress()
{
	return this->ramMemory->GetFontDataStartAddress();
}

void CPU::SetDelayTimerValue(u8 value)
{
	this->delayTimer.SetValue(value);
}

u8 CPU::GetDelayTimerValue()
{
	return this->delayTimer.GetValue();
}

void CPU::SetSoundTimerValue(u8 value)
{
	this->soundTimer.SetValue(value);
}

u8 CPU::GetPressedKey()
{
	return this->keyboard->GetPressedKey();
}

void CPU::ClearScreen()
{
	this->display->ClearScreen();
}

u8 CPU::DrawSprite(u8 *spriteData, u8 spriteWidth, u8 spriteHeight, u8 x, u8 y)
{
	return this->display->Draw(spriteData, spriteWidth, spriteHeight, x, y);
}

IInstruction* CPU::decodeInstruction(u16 rawInstruction)
{
	IInstruction *instruction = 0;
	// Unpack to nybbles and bytes to match instructions more easily
	u8 lowerByte = (u8)rawInstruction;
	u8 upperByte = (u8)(rawInstruction >> 8);

	u8 nybbleuu = ((u8)(upperByte >> 4)) & 0b00001111;
	u8 nybbleul = upperByte & 0b00001111;
	u8 nybblelu = ((u8)(lowerByte >> 4)) & 0b00001111;
	u8 nybblell = lowerByte & 0b00001111;

	if (upperByte == 0x00 && lowerByte == 0xE0)
	{
		instruction = new ClearScreenInstruction(this);
	}
	else if (upperByte == 0x00 && lowerByte == 0xEE)
	{
		instruction = new SubrutineReturnInstruction(this);
	}
	else if (nybbleuu == 0x01)
	{
		u16 address = (nybbleul << 8) | (u16)lowerByte;
		instruction = new JumpInstruction(address, this);
	}
	else if (nybbleuu == 0x02)
	{
		u16 address = (nybbleul << 8) | (u16)lowerByte;
		instruction = new CallInstruction(address, this);
	}
	else if (nybbleuu == 0x03)
	{
		instruction = new SkipNextIfVxEqualsValueInstruction(nybbleul, lowerByte, this);
	}
	else if (nybbleuu == 0x04)
	{
		instruction = new SkipNextIfVxNotEqualsValueInstruction(nybbleul, lowerByte, this);
	}
	else if (nybbleuu == 0x05 && nybblell == 0x00)
	{
		instruction = new SkipNextIfVxEqualsVyInstruction(nybbleul, nybblelu, this);
	}
	else if (nybbleuu == 0x06)
	{
		instruction = new SetVxToValueInstruction(nybbleul,lowerByte,this);
	}
	else if (nybbleuu == 0x07)
	{
		instruction = new AddValueToVxInstruction(nybbleul,lowerByte,this);
	}
	else if (nybbleuu == 0x08 && nybblell == 0x00)
	{
		instruction = new SetVxToVyInstruction(nybbleul, nybblelu, this);
	}
	else if (nybbleuu == 0x08 && nybblell == 0x01)
	{
		instruction = new SetVxToVxOrVyInstruction(nybbleul, nybblelu, this);
	}
	else if (nybbleuu == 0x08 && nybblell == 0x02)
	{
		instruction = new SetVxToVxAndVyInstruction(nybbleul, nybblelu, this);
	}
	else if (nybbleuu == 0x08 && nybblell == 0x03)
	{
		instruction = new SetVxToVxXorVyInstruction(nybbleul, nybblelu, this);
	}
	else if (nybbleuu == 0x08 && nybblell == 0x04)
	{
		instruction = new AddVyToVxInstruction(nybbleul, nybblelu, this);
	}
	else if (nybbleuu == 0x08 && nybblell == 0x05)
	{
		instruction = new SubtractVyFromVxInstruction(nybbleul, nybblelu, this);
	}
	else if (nybbleuu == 0x08 && nybblell == 0x06)
	{
		instruction = new ShiftVxRightByOneInstruction(nybbleul, this);
	}
	else if (nybbleuu == 0x08 && nybblell == 0x07)
	{
		instruction = new SetVxToVyMinusVxInstruction(nybbleul, nybblelu, this);
	}
	else if (nybbleuu == 0x08 && nybblell == 0x0E)
	{
		instruction = new ShiftVxLeftByOneInstruction(nybbleul, this);
	}
	else if (nybbleuu == 0x09 && nybblell == 0x00)
	{
		instruction = new SkipNextIfVxNotEqualsVyInstruction(nybbleul, nybblelu, this);
	}
	else if (nybbleuu == 0x0A)
	{
		u16 addressValue = (u16)(nybbleul << 8) | (u16)lowerByte;
		instruction = new SetIndexRegisterValueInstruction(addressValue, this);
	}
	else if (nybbleuu == 0x0B)
	{
		u16 addressValue = (u16)(nybbleul << 8) | (u16)lowerByte;
		instruction = new JumpToGivenAddressWithOffset(addressValue, this);
	}
	else if (nybbleuu == 0x0C)
	{
		instruction = new SetVxToRandomValueBitwiseAndValueInstruction(nybbleul, lowerByte, this);
	}
	else if (nybbleuu == 0x0D)
	{
		instruction = new DrawSpriteInstruction(nybbleul, nybblelu, nybblell, this);
	}
	else if (nybbleuu == 0x0E && lowerByte == 0x9E)
	{
		instruction = new SkipIfKeyInVxIsPressedInstruction(nybbleul, this);
	}
	else if (nybbleuu == 0x0E && lowerByte == 0xA1)
	{
		instruction = new SkipIfKeyInVxIsNotPressedInstruction(nybbleul, this);
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x07)
	{
		instruction = new SetVxToValueOfDelayTimerInstruction(nybbleul, this);
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x0A)
	{
		instruction = new WaitForKeyPressInstruction(nybbleul, this);
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x15)
	{
		instruction = new SetDelayTimerToVxInstruction(nybbleul, this);
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x18)
	{
		instruction = new SetSoundTimerToVxInstruction(nybbleul, this);
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x1E)
	{
		instruction = new AddVxToIndexRegisterInstruction(nybbleul, this);
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x29)
	{
		instruction = new SetIndexRegisterToFontCharacterInVxInstruction(nybbleul, this);
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x33)
	{
		instruction = new StoreBCDvalueOfVxInstruction(nybbleul, this);
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x55)
	{
		instruction = new StoreV0toVxInMemoryInstruction(nybbleul, this);
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x65)
	{
		instruction = new FillV0toVxWithValueFromMemoryInstruction(nybbleul, this);
	}

	if (instruction == 0)
	{
		instruction = (IInstruction*)new UnknownInstruction();
	}
	return instruction;
}





