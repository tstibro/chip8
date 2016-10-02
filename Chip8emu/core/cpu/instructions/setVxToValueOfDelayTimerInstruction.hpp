/*
 * setVxToValueOfDelayTimerInstruction.hpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SETVXTOVALUEOFDELAYTIMERINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SETVXTOVALUEOFDELAYTIMERINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SetVxToValueOfDelayTimerInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		CPU *cpu;
	public:
		SetVxToValueOfDelayTimerInstruction(u8 registerXindex, CPU *cpu);
		virtual ~SetVxToValueOfDelayTimerInstruction();
		virtual void Execute();
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_SETVXTOVALUEOFDELAYTIMERINSTRUCTION_HPP_ */
