/*
 * stack.cpp
 *
 *  Created on: Jul 16, 2016
 *      Author: Tomas Stibrany
 */
#include "stack.hpp"

using namespace chip8::core::cpu;

Stack::Stack()
{
	initialize(DEFAULT_STACK_SIZE);
}

Stack::Stack(u16 initialSize)
{
	if (initialSize == 0)
		initialSize = DEFAULT_STACK_SIZE;
	initialize(initialSize);
}

void Stack::initialize(u16 initialSize)
{
	this->allocatedSize = initialSize;
	this->items = new u16[this->allocatedSize];
	this->topIndex = 0;
}

Stack::~Stack()
{
	this->allocatedSize = 0;
	delete this->items;
}

void Stack::Push(u16 value)
{
	if (!IsFull())
	{
		topIndex += 1;
		this->items[topIndex - 1] = value;
	}
}

u16 Stack::Pop()
{
	if (!IsEmpty())
	{
		topIndex -= 1;
		return this->items[topIndex];
	}
	return 0;
}

bool Stack::IsFull()
{
	return (topIndex == allocatedSize);
}

bool Stack::IsEmpty()
{
	return (topIndex == 0);
}

