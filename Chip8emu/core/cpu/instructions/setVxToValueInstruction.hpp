/*
 * SetVxToValueInstruction.hpp
 *
 *  Created on: Jul 9, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SETVXTOVALUEINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SETVXTOVALUEINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SetVxToValueInstruction : public IInstruction
	{
	private:
		u8 gprIndex;
		u8 value;
		CPU *cpu;
	public:
		SetVxToValueInstruction(u8 gprIndex,u8 value,CPU *cpu);
		virtual ~SetVxToValueInstruction();
		virtual void Execute();
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_SETVXTOVALUEINSTRUCTION_HPP_ */
