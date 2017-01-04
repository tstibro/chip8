/*
 * gpr.hpp
 *
 *  Created on: Jul 4, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_REGISTERS_GPR_HPP_
#define CORE_CPU_REGISTERS_GPR_HPP_
#include <iostream>
#include "../../../chip8Types.hpp"

namespace chip8 { namespace core { namespace cpu { namespace registers
{
	class GeneralPurposeRegister
	{
	private:
		u8 registerContents;
	public:
		// Default constructor. Sets number of registers to 16
		GeneralPurposeRegister();
		// Destructor
		~GeneralPurposeRegister();
		// Write value to given register. Last register is not accessible for programs (Flag register);
		void Write(u8 value);
		// Read register value
		u8 Read();
	};

}}}}



#endif /* CORE_CPU_REGISTERS_GPR_HPP_ */
