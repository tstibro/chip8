/*
 * setVxToVyInstruction.hpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SETVXTOVYINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SETVXTOVYINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SetVxToVyInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		u8 registerYindex;
		CPU *cpu;
	public:
		SetVxToVyInstruction(u8 registerXindex, u8 registerYindex, CPU *cpu);
		virtual ~SetVxToVyInstruction();
		virtual void Execute();

		void SetRegisterXindex(u8 registerIndex);
		void SetRegisterYindex(u8 registerIndex);
	};

}}}}



#endif /* CORE_CPU_INSTRUCTIONS_SETVXTOVYINSTRUCTION_HPP_ */
