/*
* instructionFactory.hpp
*
*  Created on: October 2, 2016
*      Author: Tomas Stibrany
*/
#ifndef INSTRUCTIONFACTORY_HPP_	
#define INSTRUCTIONFACTORY_HPP_
#include "../../../../chip8Types.hpp"

namespace chip8 {
	namespace core {
		namespace cpu {
			class CPU;

			namespace instructions {
				class IInstruction;

				class AddValueToVxInstruction;
				class AddVxToIndexRegisterInstruction;
				class AddVyToVxInstruction;
				class CallInstruction;
				class ClearScreenInstruction;
				class DrawSpriteInstruction;
				class FillV0toVxWithValueFromMemoryInstruction;
				class JumpInstruction;
				class JumpToGivenAddressWithOffset;
				class SetDelayTimerToVxInstruction;
				class SetIndexRegisterToFontCharacterInVxInstruction;
				class SetIndexRegisterValueInstruction;
				class SetSoundTimerToVxInstruction;
				class SetVxToRandomValueBitwiseAndValueInstruction;
				class SetVxToValueInstruction;
				class SetVxToValueOfDelayTimerInstruction;
				class SetVxToVxAndVyInstruction;
				class SetVxToVxOrVyInstruction;
				class SetVxToVxXorVyInstruction;
				class SetVxToVyInstruction;
				class SetVxToVyMinusVxInstruction;
				class ShiftVxLeftByOneInstruction;
				class ShiftVxRightByOneInstruction;
				class SkipIfKeyInVxIsNotPressedInstruction;
				class SkipIfKeyInVxIsPressedInstruction;
				class SkipNextIfVxEqualsValueInstruction;
				class SkipNextIfVxEqualsVyInstruction;
				class SkipNextIfVxNotEqualsValueInstruction;
				class SkipNextIfVxNotEqualsVyInstruction;
				class StoreBCDvalueOfVxInstruction;
				class StoreV0toVxInMemoryInstruction;
				class SubrutineReturnInstruction;
				class SubtractVyFromVxInstruction;
				class WaitForKeyPressInstruction;
				class UnknownInstruction;
			}
		}
	}
}

namespace chip8 {
	namespace core {
		namespace cpu { 
			namespace instructions {

				// Instruction factory creates concrete classes of IInstruction
				//
				// Since creating new instruction instances every execution loop would be expensive,
				// this class reuses the ones already created by re-setting the attributes
				class InstructionFactory
				{
				private:
					CPU *cpu;

					AddValueToVxInstruction *addValueToVxInstruction;
					AddVxToIndexRegisterInstruction *addVxToIndexRegisterInstruction;
					AddVyToVxInstruction *addVyToVxInstruction;
					CallInstruction *callInstruction;
					ClearScreenInstruction *clearScreenInstruction;
					DrawSpriteInstruction *drawSpriteInstruction;
					FillV0toVxWithValueFromMemoryInstruction *fillV0toVxWithValueFromMemoryInstruction;
					JumpInstruction *jumpInstruction;
					JumpToGivenAddressWithOffset *jumpToGivenAddressWithOffset;
					SetDelayTimerToVxInstruction *setDelayTimerToVxInstruction;
					SetIndexRegisterToFontCharacterInVxInstruction *setIndexRegisterToFontCharacterInVxInstruction;
					SetIndexRegisterValueInstruction *setIndexRegisterValueInstruction;
					SetSoundTimerToVxInstruction *setSoundTimerToVxInstruction;
					SetVxToRandomValueBitwiseAndValueInstruction *setVxToRandomValueBitwiseAndValueInstruction;
					SetVxToValueInstruction *setVxToValueInstruction;
					SetVxToValueOfDelayTimerInstruction *setVxToValueOfDelayTimerInstruction;
					SetVxToVxAndVyInstruction *setVxToVxAndVyInstruction;
					SetVxToVxOrVyInstruction *setVxToVxOrVyInstruction;
					SetVxToVxXorVyInstruction *setVxToVxXorVyInstruction;
					SetVxToVyInstruction *setVxToVyInstruction;
					SetVxToVyMinusVxInstruction *setVxToVyMinusVxInstruction;
					ShiftVxLeftByOneInstruction *shiftVxLeftByOneInstruction;
					ShiftVxRightByOneInstruction *shiftVxRightByOneInstruction;
					SkipIfKeyInVxIsNotPressedInstruction *skipIfKeyInVxIsNotPressedInstruction;
					SkipIfKeyInVxIsPressedInstruction *skipIfKeyInVxIsPressedInstruction;
					SkipNextIfVxEqualsValueInstruction *skipNextIfVxEqualsValueInstruction;
					SkipNextIfVxEqualsVyInstruction *skipNextIfVxEqualsVyInstruction;
					SkipNextIfVxNotEqualsValueInstruction *skipNextIfVxNotEqualsValueInstruction;
					SkipNextIfVxNotEqualsVyInstruction *skipNextIfVxNotEqualsVyInstruction;
					StoreBCDvalueOfVxInstruction *storeBCDvalueOfVxInstruction;
					StoreV0toVxInMemoryInstruction *storeV0toVxInMemoryInstruction;
					SubrutineReturnInstruction *subrutineReturnInstruction;
					SubtractVyFromVxInstruction *subtractVyFromVxInstruction;
					WaitForKeyPressInstruction *waitForKeyPressInstruction;
					UnknownInstruction *unknownInstruction;
				public:
					// Constructor
					InstructionFactory(CPU *cpu); // Instructions depend on CPU class
					// Destructor
					~InstructionFactory();
					// Creates an instruction
					IInstruction *Create(u16 rawInstructionData);
				};

			}
		}
	}
}
#endif

