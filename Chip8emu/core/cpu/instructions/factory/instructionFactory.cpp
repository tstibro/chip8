#include "instructionFactory.hpp"

#include "../setIndexRegisterValueInstruction.hpp"
#include "../unknownInstruction.hpp"
#include "../setVxToValueInstruction.hpp"
#include "../addValueToVxInstruction.hpp"
#include "../setVxToVyInstruction.hpp"
#include "../setVxToVxOrVyInstruction.hpp"
#include "../setVxToVxAndVyInstruction.hpp"
#include "../setVxToVxXorVyInstruction.hpp"
#include "../addVyToVxInstruction.hpp"
#include "../subtractVyFromVxInstruction.hpp"
#include "../setVxToVyMinusVxInstruction.hpp"
#include "../shiftVxRightByOneInstruction.hpp"
#include "../shiftVxLeftByOneInstruction.hpp"
#include "../setVxToRandomValueBitwiseAndValueInstruction.hpp"
#include "../setVxToValueOfDelayTimerInstruction.hpp"
#include "../setDelayTimerToVxInstruction.hpp"
#include "../setSoundTimerToVxInstruction.hpp"
#include "../addVxToIndexRegisterInstruction.hpp"
#include "../skipNextIfVxEqualsValueInstruction.hpp"
#include "../skipNextIfVxNotEqualsValueInstruction.hpp"
#include "../skipNextIfVxEqualsVyInstruction.hpp"
#include "../skipNextIfVxNotEqualsVyInstruction.hpp"
#include "../storeV0toVxInMemoryInstruction.hpp"
#include "../fillV0toVxWithValueFromMemoryInstruction.hpp"
#include "../jumpToGivenAddressWithOffset.hpp"
#include "../jumpInstruction.hpp"
#include "../callInstruction.hpp"
#include "../subrutineReturnInstruction.hpp"
#include "../storeBCDvalueOfVxInstruction.hpp"
#include "../setIndexRegisterToFontCharacterInVxInstruction.hpp"
#include "../waitForKeyPressInstruction.hpp"
#include "../skipIfKeyInVxIsNotPressedInstruction.hpp"
#include "../skipIfKeyInVxIsPressedInstruction.hpp"
#include "../clearScreenInstruction.hpp"
#include "../drawSpriteInstruction.hpp"

using namespace chip8::core::cpu;
using namespace chip8::core::cpu::instructions;

InstructionFactory::InstructionFactory(CPU *cpu)
{
	this->cpu = cpu;

	addValueToVxInstruction = 0;
	addVxToIndexRegisterInstruction = 0;
	addVyToVxInstruction = 0;
	callInstruction = 0;
	clearScreenInstruction = 0;
	drawSpriteInstruction = 0;
	fillV0toVxWithValueFromMemoryInstruction = 0;
	jumpInstruction = 0;
	jumpToGivenAddressWithOffset = 0;
	setDelayTimerToVxInstruction = 0;
	setIndexRegisterToFontCharacterInVxInstruction = 0;
	setIndexRegisterValueInstruction = 0;
	setSoundTimerToVxInstruction = 0;
	setVxToRandomValueBitwiseAndValueInstruction = 0;
	setVxToValueInstruction = 0;
	setVxToValueOfDelayTimerInstruction = 0;
	setVxToVxAndVyInstruction = 0;
	setVxToVxOrVyInstruction = 0;
	setVxToVxXorVyInstruction = 0;
	setVxToVyInstruction = 0;
	setVxToVyMinusVxInstruction = 0;
	shiftVxLeftInstruction = 0;
	shiftVxRightInstruction = 0;
	skipIfKeyInVxIsNotPressedInstruction = 0;
	skipIfKeyInVxIsPressedInstruction = 0;
	skipNextIfVxEqualsValueInstruction = 0;
	skipNextIfVxEqualsVyInstruction = 0;
	skipNextIfVxNotEqualsValueInstruction = 0;
	skipNextIfVxNotEqualsVyInstruction = 0;
	storeBCDvalueOfVxInstruction = 0;
	storeV0toVxInMemoryInstruction = 0;
	subrutineReturnInstruction = 0;
	subtractVyFromVxInstruction = 0;
	waitForKeyPressInstruction = 0;
	unknownInstruction = 0;
}

InstructionFactory::~InstructionFactory()
{
	delete addValueToVxInstruction;
	delete addVxToIndexRegisterInstruction;
	delete addVyToVxInstruction;
	delete callInstruction;
	delete clearScreenInstruction;
	delete drawSpriteInstruction;
	delete fillV0toVxWithValueFromMemoryInstruction;
	delete jumpInstruction;
	delete jumpToGivenAddressWithOffset;
	delete setDelayTimerToVxInstruction;
	delete setIndexRegisterToFontCharacterInVxInstruction;
	delete setIndexRegisterValueInstruction;
	delete setSoundTimerToVxInstruction;
	delete setVxToRandomValueBitwiseAndValueInstruction;
	delete setVxToValueInstruction;
	delete setVxToValueOfDelayTimerInstruction;
	delete setVxToVxAndVyInstruction;
	delete setVxToVxOrVyInstruction;
	delete setVxToVxXorVyInstruction;
	delete setVxToVyInstruction;
	delete setVxToVyMinusVxInstruction;
	delete shiftVxLeftInstruction;
	delete shiftVxRightInstruction;
	delete skipIfKeyInVxIsNotPressedInstruction;
	delete skipIfKeyInVxIsPressedInstruction;
	delete skipNextIfVxEqualsValueInstruction;
	delete skipNextIfVxEqualsVyInstruction;
	delete skipNextIfVxNotEqualsValueInstruction;
	delete skipNextIfVxNotEqualsVyInstruction;
	delete storeBCDvalueOfVxInstruction;
	delete storeV0toVxInMemoryInstruction;
	delete subrutineReturnInstruction;
	delete subtractVyFromVxInstruction;
	delete waitForKeyPressInstruction;
	delete unknownInstruction;
}

IInstruction *InstructionFactory::Create(u16 rawInstructionData)
{
	IInstruction *instruction = 0;
	// Unpack to nybbles and bytes to match instructions more easily
	u8 lowerByte = (u8)rawInstructionData;
	u8 upperByte = (u8)(rawInstructionData >> 8);

	u8 nybbleuu = ((u8)(upperByte >> 4)) & 0b00001111;
	u8 nybbleul = upperByte & 0b00001111;
	u8 nybblelu = ((u8)(lowerByte >> 4)) & 0b00001111;
	u8 nybblell = lowerByte & 0b00001111;

	if (upperByte == 0x00 && lowerByte == 0xE0)
	{
		if (clearScreenInstruction == 0)
			clearScreenInstruction = new ClearScreenInstruction(cpu);
		instruction = clearScreenInstruction;
	}
	else if (upperByte == 0x00 && lowerByte == 0xEE)
	{
		if (subrutineReturnInstruction == 0)
			subrutineReturnInstruction = new SubrutineReturnInstruction(cpu);
		instruction = subrutineReturnInstruction;
	}
	else if (nybbleuu == 0x01)
	{
		u16 address = ((u16)nybbleul << 8) | (u16)lowerByte;
		if (jumpInstruction == 0)
			jumpInstruction = new JumpInstruction(address, cpu);
		else
			jumpInstruction->SetAddress(address);
		instruction = jumpInstruction;
	}
	else if (nybbleuu == 0x02)
	{
		u16 address = ((u16)nybbleul << 8) | (u16)lowerByte;
		if (callInstruction == 0)
			callInstruction = new CallInstruction(address, cpu);
		else
			callInstruction->SetAddress(address);
		instruction = callInstruction;
	}
	else if (nybbleuu == 0x03)
	{
		if (skipNextIfVxEqualsValueInstruction == 0)
			skipNextIfVxEqualsValueInstruction = new SkipNextIfVxEqualsValueInstruction(nybbleul, lowerByte, cpu);
		else
		{
			skipNextIfVxEqualsValueInstruction->SetRegisterXindex(nybbleul);
			skipNextIfVxEqualsValueInstruction->SetValue(lowerByte);
		}
		instruction = skipNextIfVxEqualsValueInstruction;
	}
	else if (nybbleuu == 0x04)
	{
		if (skipNextIfVxNotEqualsValueInstruction == 0)
			skipNextIfVxNotEqualsValueInstruction = new SkipNextIfVxNotEqualsValueInstruction(nybbleul, lowerByte, cpu);
		else
		{
			skipNextIfVxNotEqualsValueInstruction->SetRegisterXindex(nybbleul);
			skipNextIfVxNotEqualsValueInstruction->SetValue(lowerByte);
		}
		instruction = skipNextIfVxNotEqualsValueInstruction;
	}
	else if (nybbleuu == 0x05 && nybblell == 0x00)
	{
		if (skipNextIfVxEqualsVyInstruction == 0)
			skipNextIfVxEqualsVyInstruction = new SkipNextIfVxEqualsVyInstruction(nybbleul, nybblelu, cpu);
		else
		{
			skipNextIfVxEqualsVyInstruction->SetRegisterXindex(nybbleul);
			skipNextIfVxEqualsVyInstruction->SetRegisterYindex(nybblelu);
		}
		instruction = skipNextIfVxEqualsVyInstruction;
	}
	else if (nybbleuu == 0x06)
	{
		if (setVxToValueInstruction == 0)
			setVxToValueInstruction = new SetVxToValueInstruction(nybbleul, lowerByte, cpu);
		else
		{
			setVxToValueInstruction->SetRegisterXindex(nybbleul);
			setVxToValueInstruction->SetValue(lowerByte);
		}
		instruction = setVxToValueInstruction;
	}
	else if (nybbleuu == 0x07)
	{
		if (addValueToVxInstruction == 0)
			addValueToVxInstruction = new AddValueToVxInstruction(nybbleul, lowerByte, cpu);
		else
		{
			addValueToVxInstruction->SetRegisterXindex(nybbleul);
			addValueToVxInstruction->SetValue(lowerByte);
		}
		instruction = addValueToVxInstruction;
	}
	else if (nybbleuu == 0x08 && nybblell == 0x00)
	{
		if (setVxToVyInstruction == 0)
			setVxToVyInstruction = new SetVxToVyInstruction(nybbleul, nybblelu, cpu);
		else
		{
			setVxToVyInstruction->SetRegisterXindex(nybbleul);
			setVxToVyInstruction->SetRegisterYindex(nybblelu);
		}
		instruction = setVxToVyInstruction;
	}
	else if (nybbleuu == 0x08 && nybblell == 0x01)
	{
		if (setVxToVxOrVyInstruction == 0)
			setVxToVxOrVyInstruction = new SetVxToVxOrVyInstruction(nybbleul, nybblelu, cpu);
		else
		{
			setVxToVxOrVyInstruction->SetRegisterXindex(nybbleul);
			setVxToVxOrVyInstruction->SetRegisterYindex(nybblelu);
		}
		instruction = setVxToVxOrVyInstruction;
	}
	else if (nybbleuu == 0x08 && nybblell == 0x02)
	{
		if (setVxToVxAndVyInstruction == 0)
			setVxToVxAndVyInstruction = new SetVxToVxAndVyInstruction(nybbleul, nybblelu, cpu);
		else
		{
			setVxToVxAndVyInstruction->SetRegisterXindex(nybbleul);
			setVxToVxAndVyInstruction->SetRegisterYindex(nybblelu);
		}
		instruction = setVxToVxAndVyInstruction;
	}
	else if (nybbleuu == 0x08 && nybblell == 0x03)
	{
		if (setVxToVxXorVyInstruction == 0)
			setVxToVxXorVyInstruction = new SetVxToVxXorVyInstruction(nybbleul, nybblelu, cpu);
		else
		{
			setVxToVxXorVyInstruction->SetRegisterXindex(nybbleul);
			setVxToVxXorVyInstruction->SetRegisterYindex(nybblelu);
		}
		instruction = setVxToVxXorVyInstruction;
	}
	else if (nybbleuu == 0x08 && nybblell == 0x04)
	{
		if (addVyToVxInstruction == 0)
			addVyToVxInstruction = new AddVyToVxInstruction(nybbleul, nybblelu, cpu);
		else
		{
			addVyToVxInstruction->SetRegisterYindex(nybbleul);
			addVyToVxInstruction->SetRegisterXindex(nybblelu);
		}
		instruction = addVyToVxInstruction;
	}
	else if (nybbleuu == 0x08 && nybblell == 0x05)
	{
		if (subtractVyFromVxInstruction == 0)
			subtractVyFromVxInstruction = new SubtractVyFromVxInstruction(nybbleul, nybblelu, cpu);
		else
		{
			subtractVyFromVxInstruction->SetRegisterYindex(nybbleul);
			subtractVyFromVxInstruction->SetRegisterXindex(nybblelu);
		}
		instruction = subtractVyFromVxInstruction;
	}
	else if (nybbleuu == 0x08 && nybblell == 0x06)
	{
		if (shiftVxRightInstruction == 0)
			shiftVxRightInstruction = new ShiftVxRightInstruction(nybbleul, nybblelu,cpu);
		else
		{
			shiftVxRightInstruction->SetRegisterXindex(nybbleul);
			shiftVxRightInstruction->SetRegisterYindex(nybblelu);
		}
		instruction = shiftVxRightInstruction;
	}
	else if (nybbleuu == 0x08 && nybblell == 0x07)
	{
		if (setVxToVyMinusVxInstruction == 0)
			setVxToVyMinusVxInstruction = new SetVxToVyMinusVxInstruction(nybbleul, nybblelu, cpu);
		else
		{
			setVxToVyMinusVxInstruction->SetRegisterXindex(nybbleul);
			setVxToVyMinusVxInstruction->SetRegisterYindex(nybblelu);
		}
		instruction = setVxToVyMinusVxInstruction;
	}
	else if (nybbleuu == 0x08 && nybblell == 0x0E)
	{
		if (shiftVxLeftInstruction == 0)
			shiftVxLeftInstruction = new ShiftVxLeftInstruction(nybbleul, nybblelu,cpu);
		else
		{
			shiftVxLeftInstruction->SetRegisterXindex(nybbleul);
			shiftVxLeftInstruction->SetRegisterYindex(nybblelu);
		}
		instruction = shiftVxLeftInstruction;
	}
	else if (nybbleuu == 0x09 && nybblell == 0x00)
	{
		if (skipNextIfVxNotEqualsVyInstruction == 0)
			skipNextIfVxNotEqualsVyInstruction = new SkipNextIfVxNotEqualsVyInstruction(nybbleul, nybblelu, cpu);
		else
		{
			skipNextIfVxNotEqualsVyInstruction->SetRegisterXindex(nybbleul);
			skipNextIfVxNotEqualsVyInstruction->SetRegisterYindex(nybblelu);
		}
		instruction = skipNextIfVxNotEqualsVyInstruction;
	}
	else if (nybbleuu == 0x0A)
	{
		u16 addressValue = ((u16)nybbleul << 8) | (u16)lowerByte;
		if (setIndexRegisterValueInstruction == 0)
			setIndexRegisterValueInstruction = new SetIndexRegisterValueInstruction(addressValue, cpu);
		else
		{
			setIndexRegisterValueInstruction->SetAddress(addressValue);
		}
		instruction = setIndexRegisterValueInstruction;
	}
	else if (nybbleuu == 0x0B)
	{
		u16 addressValue = ((u16)nybbleul << 8) | (u16)lowerByte;
		if (jumpToGivenAddressWithOffset == 0)
			jumpToGivenAddressWithOffset = new JumpToGivenAddressWithOffset(addressValue, cpu);
		else
		{
			jumpToGivenAddressWithOffset->SetAddress(addressValue);
		}
		instruction = jumpToGivenAddressWithOffset;
	}
	else if (nybbleuu == 0x0C)
	{
		if (setVxToRandomValueBitwiseAndValueInstruction == 0)
			setVxToRandomValueBitwiseAndValueInstruction = new SetVxToRandomValueBitwiseAndValueInstruction(nybbleul, lowerByte, cpu);
		else
		{
			setVxToRandomValueBitwiseAndValueInstruction->SetRegisterXindex(nybbleul);
			setVxToRandomValueBitwiseAndValueInstruction->SetValue(lowerByte);
		}
		instruction = setVxToRandomValueBitwiseAndValueInstruction;
	}
	else if (nybbleuu == 0x0D)
	{
		if (drawSpriteInstruction == 0)
			drawSpriteInstruction = new DrawSpriteInstruction(nybbleul, nybblelu, nybblell, cpu);
		else
		{
			drawSpriteInstruction->SetRegisterXindex(nybbleul);
			drawSpriteInstruction->SetRegisterYindex(nybblelu);
			drawSpriteInstruction->SetSpriteHeight(nybblell);
		}
		instruction = drawSpriteInstruction;
	}
	else if (nybbleuu == 0x0E && lowerByte == 0x9E)
	{
		if (skipIfKeyInVxIsPressedInstruction == 0)
			skipIfKeyInVxIsPressedInstruction = new SkipIfKeyInVxIsPressedInstruction(nybbleul, cpu);
		else
		{
			skipIfKeyInVxIsPressedInstruction->SetRegisterXindex(nybbleul);
		}
		instruction = skipIfKeyInVxIsPressedInstruction;
	}
	else if (nybbleuu == 0x0E && lowerByte == 0xA1)
	{
		if (skipIfKeyInVxIsNotPressedInstruction == 0)
			skipIfKeyInVxIsNotPressedInstruction = new SkipIfKeyInVxIsNotPressedInstruction(nybbleul, cpu);
		else
		{
			skipIfKeyInVxIsNotPressedInstruction->SetRegisterXindex(nybbleul);
		}
		instruction = skipIfKeyInVxIsNotPressedInstruction;
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x07)
	{
		if (setVxToValueOfDelayTimerInstruction == 0)
			setVxToValueOfDelayTimerInstruction = new SetVxToValueOfDelayTimerInstruction(nybbleul, cpu);
		else
		{
			setVxToValueOfDelayTimerInstruction->SetRegisterXindex(nybbleul);
		}
		instruction = setVxToValueOfDelayTimerInstruction;
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x0A)
	{
		if (waitForKeyPressInstruction == 0)
			waitForKeyPressInstruction = new WaitForKeyPressInstruction(nybbleul, cpu);
		else
		{
			waitForKeyPressInstruction->SetRegisterXindex(nybbleul);
		}
		instruction = waitForKeyPressInstruction;
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x15)
	{
		if (setDelayTimerToVxInstruction == 0)
			setDelayTimerToVxInstruction = new SetDelayTimerToVxInstruction(nybbleul, cpu);
		else
		{
			setDelayTimerToVxInstruction->SetRegisterXindex(nybbleul);
		}
		instruction = setDelayTimerToVxInstruction;
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x18)
	{
		if (setSoundTimerToVxInstruction == 0)
			setSoundTimerToVxInstruction = new SetSoundTimerToVxInstruction(nybbleul, cpu);
		else
		{
			setSoundTimerToVxInstruction->SetRegisterXindex(nybbleul);
		}
		instruction = setSoundTimerToVxInstruction;
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x1E)
	{
		if (addVxToIndexRegisterInstruction == 0)
			addVxToIndexRegisterInstruction = new AddVxToIndexRegisterInstruction(nybbleul, cpu);
		else
		{
			addVxToIndexRegisterInstruction->SetRegisterXindex(nybbleul);
		}
		instruction = addVxToIndexRegisterInstruction;
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x29)
	{
		if (setIndexRegisterToFontCharacterInVxInstruction == 0)
			setIndexRegisterToFontCharacterInVxInstruction = new SetIndexRegisterToFontCharacterInVxInstruction(nybbleul, cpu);
		else
		{
			setIndexRegisterToFontCharacterInVxInstruction->SetRegisterXindex(nybbleul);
		}
		instruction = setIndexRegisterToFontCharacterInVxInstruction;
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x33)
	{
		if (storeBCDvalueOfVxInstruction == 0)
			storeBCDvalueOfVxInstruction = new StoreBCDvalueOfVxInstruction(nybbleul, cpu);
		else
		{
			storeBCDvalueOfVxInstruction->SetRegisterXindex(nybbleul);
		}
		instruction = storeBCDvalueOfVxInstruction;
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x55)
	{
		if (storeV0toVxInMemoryInstruction == 0)
			storeV0toVxInMemoryInstruction = new StoreV0toVxInMemoryInstruction(nybbleul, cpu);
		else
		{
			storeV0toVxInMemoryInstruction->SetRegisterXindex(nybbleul);
		}
		instruction = storeV0toVxInMemoryInstruction;
	}
	else if (nybbleuu == 0x0F && lowerByte == 0x65)
	{
		if (fillV0toVxWithValueFromMemoryInstruction == 0)
			fillV0toVxWithValueFromMemoryInstruction = new FillV0toVxWithValueFromMemoryInstruction(nybbleul, cpu);
		else
		{
			fillV0toVxWithValueFromMemoryInstruction->SetRegisterXindex(nybbleul);
		}
		instruction = fillV0toVxWithValueFromMemoryInstruction;
	}

	if (instruction == 0)
	{
		if (unknownInstruction == 0)
			unknownInstruction = new UnknownInstruction();
		instruction = unknownInstruction;
	}
	return instruction;
}