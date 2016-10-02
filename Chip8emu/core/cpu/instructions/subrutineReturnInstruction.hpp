/*
 * subrutineReturnInstruction.hpp
 *
 *  Created on: Jul 21, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SUBRUTINERETURNINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SUBRUTINERETURNINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SubrutineReturnInstruction : public IInstruction
	{
	private:
		CPU *cpu;
	public:
		SubrutineReturnInstruction(CPU *cpu);
		virtual ~SubrutineReturnInstruction();
		virtual void Execute();
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_SUBRUTINERETURNINSTRUCTION_HPP_ */
