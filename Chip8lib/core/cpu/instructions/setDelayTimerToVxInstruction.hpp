/*
 * setDelayTimerToVxInstruction.hpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SETDELAYTIMERTOVXINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SETDELAYTIMERTOVXINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SetDelayTimerToVxInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		CPU *cpu;
	public:
		SetDelayTimerToVxInstruction(u8 registerXindex, CPU *cpu);
		virtual ~SetDelayTimerToVxInstruction();
		virtual void Execute();

		void SetRegisterXindex(u8 registerIndex);
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_SETDELAYTIMERTOVXINSTRUCTION_HPP_ */
