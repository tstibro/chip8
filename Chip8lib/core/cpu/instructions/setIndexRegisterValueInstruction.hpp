/*
 * setAddressRegisterValueInstruction.hpp
 *
 *  Created on: Jul 13, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SETINDEXREGISTERVALUEINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SETINDEXREGISTERVALUEINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SetIndexRegisterValueInstruction : public IInstruction
	{
	private:
		CPU *cpu;
		u16 value;
	public:
		SetIndexRegisterValueInstruction(u16 value, CPU *cpu);
		virtual ~SetIndexRegisterValueInstruction();
		virtual void Execute();

		void SetAddress(u16 value);
	};

}}}}



#endif /* CORE_CPU_INSTRUCTIONS_SETINDEXREGISTERVALUEINSTRUCTION_HPP_ */
