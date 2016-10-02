/*
 * skipNextIfVxEqualsVyInstruction.hpp
 *
 *  Created on: Jul 18, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SKIPNEXTIFVXEQUALSVYINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SKIPNEXTIFVXEQUALSVYINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SkipNextIfVxEqualsVyInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		u8 registerYindex;
		CPU *cpu;
	public:
		SkipNextIfVxEqualsVyInstruction(u8 registerXindex, u8 registerYindex, CPU *cpu);
		virtual ~SkipNextIfVxEqualsVyInstruction();
		virtual void Execute();
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_SKIPNEXTIFVXEQUALSVYINSTRUCTION_HPP_ */
