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
	// Shifts value in Vx left by value in Vy
	class ShiftVxLeftInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		u8 registerYindex;
		CPU *cpu;
	public:
		ShiftVxLeftInstruction(u8 registerXindex, u8 registerYindex,CPU *cpu);
		virtual ~ShiftVxLeftInstruction();
		virtual void Execute();

		void SetRegisterXindex(u8 registerIndex);
		void SetRegisterYindex(u8 registerIndex);
	};

}}}}



#endif /* CORE_CPU_INSTRUCTIONS_SHIFTVXLEFTBYONEINSTRUCTION_HPP_ */
