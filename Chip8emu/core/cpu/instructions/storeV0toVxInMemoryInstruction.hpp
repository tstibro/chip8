/*
 * storeV0toVxInMemoryInstruction.hpp
 *
 *  Created on: Jul 19, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_STOREV0TOVXINMEMORYINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_STOREV0TOVXINMEMORYINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class StoreV0toVxInMemoryInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		CPU *cpu;
	public:
		StoreV0toVxInMemoryInstruction(u8 registerXindex, CPU *cpu);
		virtual ~StoreV0toVxInMemoryInstruction();
		virtual void Execute();
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_STOREV0TOVXINMEMORYINSTRUCTION_HPP_ */
