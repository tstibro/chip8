/*
* cpu.cpp
*
*  Created on: Jul 4, 2016
*      Author: Tomas Stibrany
*/
#include "cpu.hpp"
#include "../memory/ram.hpp"
#include "instructions/iinstruction.hpp"
#include "instructions/factory/instructionFactory.hpp"
#include "../../keyboard/keyboard.hpp"
#include "../gpu/gpu.hpp"

using chip8::core::cpu::CPU;
using namespace chip8::core::cpu::instructions;

CPU::CPU(RAM *ramMemory, GPU *gpu, Keyboard *keyboard)
{
	this->ramMemory = ramMemory;
	this->gpu = gpu;
	this->keyboard = keyboard;
	this->timerTicks = 0;
	// Lets set the starting address of programCounter right now
	this->programCounter = new ProgramCounterRegister(ramMemory->GetProgramSegmentStartAddress());
	instructionFactory = new InstructionFactory(this);
}


CPU::~CPU()
{
	delete programCounter;
	delete instructionFactory;
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
	IInstruction *instruction = instructionFactory->Create(rawInstruction);
	programCounter->Unlock(); // Allow changes of program counter (Jump instruction, ...)
	instruction->Execute();

	setNextInstruction();
}

void CPU::SkipNextInstruction()
{
	setNextInstruction();
}

void CPU::RepeatInstruction()
{
	// When an instruction calls this method, PC register is not incremented 
	// at the end of ExecuteInstruction, thus current instruction will be repeated
	programCounter->Lock();
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
	u16 address = this->stack.top();
	this->stack.pop();
	return address;
}

void CPU::WriteToGeneralPurposeRegister(u8 registerIndex, u8 value)
{
	u8 safeRegisterIndex = (registerIndex % GPR_COUNT);
	this->generalPurposeRegister[safeRegisterIndex].Write(value);
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

u8 CPU::GetSoundTimerValue()
{
	return this->soundTimer.GetValue();
}

void CPU::TimerTick()
{
	if (timerTicks++ > TIMER_TICK_INTERVAL)
	{
		timerTicks -= TIMER_TICK_INTERVAL;
		this->delayTimer.Tick();
		this->soundTimer.Tick();
	}
}

bool CPU::isAnyKeyPressed()
{
	return this->keyboard->isAnyKeyPressed();
}

bool CPU::isKeyPressed(u8 keyCode)
{
	return this->keyboard->isKeyPressed(keyCode);
}

u8 CPU::GetLastPressedKey()
{
	return this->keyboard->GetLastPressedKey();
}

void CPU::ClearScreen()
{
	this->gpu->ClearScreen();
}

u8 CPU::DrawSprite(u8 *spriteData, u8 spriteHeight, u8 x, u8 y)
{
	return this->gpu->Draw(spriteData, spriteHeight, x, y);
}





