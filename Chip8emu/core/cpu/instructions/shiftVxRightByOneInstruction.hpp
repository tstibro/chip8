/*
 * shiftVxRightByOneInstruction.hpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SHIFTVXRIGHTBYONEINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SHIFTVXRIGHTBYONEINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class ShiftVxRightByOneInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		CPU *cpu;
	public:
		ShiftVxRightByOneInstruction(u8 registerXindex, CPU *cpu);
		virtual ~ShiftVxRightByOneInstruction();
		virtual void Execute();

		void SetRegisterXindex(u8 registerIndex);
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_SHIFTVXRIGHTBYONEINSTRUCTION_HPP_ */
