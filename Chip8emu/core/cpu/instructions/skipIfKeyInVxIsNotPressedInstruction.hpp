/*
 * skipIfKeyInVxIsNotPressedInstruction.hpp
 *
 *  Created on: Jul 31, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SKIPIFKEYINVXISNOTPRESSEDINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SKIPIFKEYINVXISNOTPRESSEDINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SkipIfKeyInVxIsNotPressedInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		CPU *cpu;
	public:
		SkipIfKeyInVxIsNotPressedInstruction(u8 registerXindex, CPU *cpu);
		virtual ~SkipIfKeyInVxIsNotPressedInstruction();
		virtual void Execute();
	};

}}}}


#endif /* CORE_CPU_INSTRUCTIONS_SKIPIFKEYINVXISNOTPRESSEDINSTRUCTION_HPP_ */
