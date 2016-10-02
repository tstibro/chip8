/*
 * ri.hpp
 *
 *  Created on: Jul 5, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_REGISTERS_RI_HPP_
#define CORE_CPU_REGISTERS_RI_HPP_
#include <iostream>

namespace chip8 { namespace core { namespace cpu { namespace registers
{

	class IndexRegister
	{
	private:
		uint16_t registerContents;
	public:
		// Default constructor
		IndexRegister();
		// Destructor
		~IndexRegister();
		// Write value to register.
		void Write(uint16_t value);
		// Read register value
		uint16_t Read();
		// Increments registerContents by 1
		void Increment();
		// Decrements registerContents by 1
		void Decrement();
	};

}}}}



#endif /* CORE_CPU_REGISTERS_RI_HPP_ */
