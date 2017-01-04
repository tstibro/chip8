/*
 * unknownInstruction.hpp
 *
 *  Created on: Jul 9, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_UNKNOWNINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_UNKNOWNINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class UnknownInstruction : public IInstruction
	{
	public:
		UnknownInstruction();
		~UnknownInstruction();
		virtual void Execute();
	};

}}}}



#endif /* CORE_CPU_INSTRUCTIONS_UNKNOWNINSTRUCTION_HPP_ */
