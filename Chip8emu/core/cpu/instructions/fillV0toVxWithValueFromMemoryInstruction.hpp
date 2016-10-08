/*
 * fillV0toVxWithValueFromMemoryInstruction.hpp
 *
 *  Created on: Jul 19, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_FILLV0TOVXWITHVALUEFROMMEMORYINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_FILLV0TOVXWITHVALUEFROMMEMORYINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"


namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class FillV0toVxWithValueFromMemoryInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		CPU *cpu;
	public:
		FillV0toVxWithValueFromMemoryInstruction(u8 registerXindex, CPU *cpu);
		virtual ~FillV0toVxWithValueFromMemoryInstruction();
		virtual void Execute();

		void SetRegisterXindex(u8 registerIndex);
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_FILLV0TOVXWITHVALUEFROMMEMORYINSTRUCTION_HPP_ */
