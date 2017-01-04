/*
 * skipNextIfVxEqualsValueInstruction.hpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SKIPNEXTIFVXEQUALSVALUEINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SKIPNEXTIFVXEQUALSVALUEINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SkipNextIfVxEqualsValueInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		u8 value;
		CPU *cpu;
	public:
		SkipNextIfVxEqualsValueInstruction(u8 registerXindex, u8 value, CPU *cpu);
		virtual ~SkipNextIfVxEqualsValueInstruction();
		virtual void Execute();

		void SetRegisterXindex(u8 registerIndex);
		void SetValue(u8 value);
	};

}}}}



#endif /* CORE_CPU_INSTRUCTIONS_SKIPNEXTIFVXEQUALSVALUEINSTRUCTION_HPP_ */
