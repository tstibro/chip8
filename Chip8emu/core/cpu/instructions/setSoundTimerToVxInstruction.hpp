/*
 * setSoundTimerToVxInstruction.hpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas
 */

#ifndef CORE_CPU_INSTRUCTIONS_SETSOUNDTIMERTOVXINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SETSOUNDTIMERTOVXINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SetSoundTimerToVxInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		CPU *cpu;
	public:
		SetSoundTimerToVxInstruction(u8 registerXindex, CPU *cpu);
		virtual ~SetSoundTimerToVxInstruction();
		virtual void Execute();
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_SETSOUNDTIMERTOVXINSTRUCTION_HPP_ */
