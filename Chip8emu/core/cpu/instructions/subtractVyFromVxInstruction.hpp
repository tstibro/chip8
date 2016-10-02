/*
 * subtractVyFromVxInstruction.hpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SUBTRACTVYFROMVXINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SUBTRACTVYFROMVXINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SubtractVyFromVxInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		u8 registerYindex;
		CPU *cpu;
	public:
		SubtractVyFromVxInstruction(u8 registerYindex, u8 registerXindex, CPU *cpu);
		virtual ~SubtractVyFromVxInstruction();
		virtual void Execute();
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_SUBTRACTVYFROMVXINSTRUCTION_HPP_ */
