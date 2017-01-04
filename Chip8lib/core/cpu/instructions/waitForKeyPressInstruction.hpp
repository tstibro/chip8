/*
 * waitForKeyPressInstruction.hpp
 *
 *  Created on: Jul 30, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_WAITFORKEYPRESSINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_WAITFORKEYPRESSINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class WaitForKeyPressInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		CPU *cpu;
	public:
		WaitForKeyPressInstruction(u8 registerXindex, CPU *cpu);
		virtual ~WaitForKeyPressInstruction();
		virtual void Execute();

		void SetRegisterXindex(u8 registerIndex);
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_WAITFORKEYPRESSINSTRUCTION_HPP_ */
