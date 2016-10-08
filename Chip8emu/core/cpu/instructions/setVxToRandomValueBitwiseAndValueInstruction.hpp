/*
 * setVxToRandomValueBitwiseAndValueInstruction.hpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SETVXTORANDOMVALUEBITWISEANDVALUEINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SETVXTORANDOMVALUEBITWISEANDVALUEINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SetVxToRandomValueBitwiseAndValueInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		u8 value;
		CPU *cpu;
	public:
		SetVxToRandomValueBitwiseAndValueInstruction(u8 registerXindex, u8 value, CPU *cpu);
		virtual ~SetVxToRandomValueBitwiseAndValueInstruction();
		virtual void Execute();

		void SetRegisterXindex(u8 registerIndex);
		void SetValue(u8 value);
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_SETVXTORANDOMVALUEBITWISEANDVALUEINSTRUCTION_HPP_ */
