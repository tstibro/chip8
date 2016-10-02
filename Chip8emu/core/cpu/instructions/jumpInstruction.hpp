/*
 * jumpInstruction.hpp
 *
 *  Created on: Jul 21, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_JUMPINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_JUMPINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class JumpInstruction : public IInstruction
	{
	private:
		u16 address;
		CPU *cpu;
	public:
		JumpInstruction(u16 address, CPU *cpu);
		virtual ~JumpInstruction();
		virtual void Execute();
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_JUMPINSTRUCTION_HPP_ */
