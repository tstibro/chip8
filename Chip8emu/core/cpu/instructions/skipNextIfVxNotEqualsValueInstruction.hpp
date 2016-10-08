/*
 * skipNextIfVxNotEqualsValueInstruction.hpp
 *
 *  Created on: Jul 18, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SKIPNEXTIFVXNOTEQUALSVALUEINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SKIPNEXTIFVXNOTEQUALSVALUEINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SkipNextIfVxNotEqualsValueInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		u8 value;
		CPU *cpu;
	public:
		SkipNextIfVxNotEqualsValueInstruction(u8 registerXindex, u8 value, CPU *cpu);
		virtual ~SkipNextIfVxNotEqualsValueInstruction();
		virtual void Execute();

		void SetRegisterXindex(u8 registerIndex);
		void SetValue(u8 value);
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_SKIPNEXTIFVXNOTEQUALSVALUEINSTRUCTION_HPP_ */
