/*
 * IInstruction.hpp
 *
 *  Created on: Jul 6, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_IINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_IINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class IInstruction
	{
	public:
		IInstruction();
		virtual ~IInstruction();
		virtual void Execute();
	};

}}}}



#endif /* CORE_CPU_INSTRUCTIONS_IINSTRUCTION_HPP_ */
