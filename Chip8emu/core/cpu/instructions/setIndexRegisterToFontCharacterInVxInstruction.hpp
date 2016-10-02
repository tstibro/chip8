/*
 * setAddressRegisterToFontCharacterInVxInstruction.hpp
 *
 *  Created on: Jul 25, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_SETINDEXREGISTERTOFONTCHARACTERINVXINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_SETINDEXREGISTERTOFONTCHARACTERINVXINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class SetIndexRegisterToFontCharacterInVxInstruction : public IInstruction
	{
	private:
		u8 registerXindex;
		CPU *cpu;
	public:
		SetIndexRegisterToFontCharacterInVxInstruction(u8 registerXindex, CPU *cpu);
		virtual ~SetIndexRegisterToFontCharacterInVxInstruction();
		virtual void Execute();
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_SETINDEXREGISTERTOFONTCHARACTERINVXINSTRUCTION_HPP_ */
