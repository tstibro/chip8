/*
 * callInstruction.hpp
 *
 *  Created on: Jul 21, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_CALLINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_CALLINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class CallInstruction : public IInstruction
	{
	private:
		u16 address;
		CPU *cpu;
	public:
		CallInstruction(u16 address, CPU *cpu);
		virtual ~CallInstruction();
		virtual void Execute();

		void SetAddress(u16 address);
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_CALLINSTRUCTION_HPP_ */
