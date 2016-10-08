/*
 * jumpToGivenAddressWithOffset.hpp
 *
 *  Created on: Jul 20, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_JUMPTOGIVENADDRESSWITHOFFSET_HPP_
#define CORE_CPU_INSTRUCTIONS_JUMPTOGIVENADDRESSWITHOFFSET_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class JumpToGivenAddressWithOffset : public IInstruction
	{
	private:
		u16 address;
		CPU *cpu;
	public:
		JumpToGivenAddressWithOffset(u16 address, CPU *cpu);
		virtual ~JumpToGivenAddressWithOffset();
		virtual void Execute();

		void SetAddress(u16 address);
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_JUMPTOGIVENADDRESSWITHOFFSET_HPP_ */
