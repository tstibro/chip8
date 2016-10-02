/*
 * stack.hpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_STACK_HPP_
#define CORE_CPU_STACK_HPP_
#include "../chip8Types.hpp"

#define DEFAULT_STACK_SIZE 16

namespace chip8 { namespace core { namespace cpu
{

	class Stack
	{
	private:
		u16 allocatedSize;
		u16 *items;
		u16 topIndex;
		void initialize(u16 initialSize);
	public:
		Stack(u16 initialSize);
		Stack();
		~Stack();

		void Push(u16 value);
		u16 Pop();
		bool IsFull();
		bool IsEmpty();
	};

}}}




#endif /* CORE_CPU_STACK_HPP_ */
