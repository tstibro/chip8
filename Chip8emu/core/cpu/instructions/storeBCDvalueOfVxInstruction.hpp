/*
 * storeBCDvalueOfVxInsrtruction.hpp
 *
 *  Created on: Jul 23, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_STOREBCDVALUEOFVXINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_STOREBCDVALUEOFVXINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class StoreBCDvalueOfVxInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		CPU *cpu;
	public:
		StoreBCDvalueOfVxInstruction(u8 registerXindex, CPU *cpu);
		virtual ~StoreBCDvalueOfVxInstruction();
		virtual void Execute();

		void SetRegisterXindex(u8 registerIndex);
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_STOREBCDVALUEOFVXINSTRUCTION_HPP_ */
