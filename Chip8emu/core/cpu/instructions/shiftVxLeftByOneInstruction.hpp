/*
 * shiftVxLeftByOneInstruction.hpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SHIFTVXLEFTBYONEINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SHIFTVXLEFTBYONEINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class ShiftVxLeftByOneInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		CPU *cpu;
	public:
		ShiftVxLeftByOneInstruction(u8 registerXindex, CPU *cpu);
		virtual ~ShiftVxLeftByOneInstruction();
		virtual void Execute();
	};

}}}}



#endif /* CORE_CPU_INSTRUCTIONS_SHIFTVXLEFTBYONEINSTRUCTION_HPP_ */
