/*
 * clearScreenInstruction.hpp
 *
 *  Created on: Aug 1, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_CLEARSCREENINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_CLEARSCREENINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"


namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class ClearScreenInstruction : public IInstruction
	{
	private:
		CPU *cpu;
	public:
		ClearScreenInstruction(CPU *cpu);
		virtual ~ClearScreenInstruction();
		virtual void Execute();
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_CLEARSCREENINSTRUCTION_HPP_ */
