/*
 * addValueToVxInstruction.hpp
 *
 *  Created on: Jul 14, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_ADDVALUETOVXINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_ADDVALUETOVXINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}


namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class AddValueToVxInstruction : public IInstruction
	{
	private:
		u8 registerIndex;
		u8 value;
		CPU *cpu;
	public:
		AddValueToVxInstruction(u8 registerIndex, u8 value, CPU *cpu);
		virtual ~AddValueToVxInstruction();
		virtual void Execute();

		void SetRegisterXindex(u8 registerIndex);
		void SetValue(u8 value);
	};

}}}}



#endif /* CORE_CPU_INSTRUCTIONS_ADDVALUETOVXINSTRUCTION_HPP_ */
