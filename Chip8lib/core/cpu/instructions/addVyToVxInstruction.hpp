/*
 * addVyToVxInstruction.hpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_ADDVYTOVXINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_ADDVYTOVXINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class AddVyToVxInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		u8 registerYindex;
		CPU *cpu;
	public:
		AddVyToVxInstruction(u8 registerYindex, u8 registerXindex, CPU *cpu);
		virtual ~AddVyToVxInstruction();
		virtual void Execute();

		void SetRegisterXindex(u8 registerIndex);
		void SetRegisterYindex(u8 registerIndex);
	};

}}}}



#endif /* CORE_CPU_INSTRUCTIONS_ADDVYTOVXINSTRUCTION_HPP_ */
