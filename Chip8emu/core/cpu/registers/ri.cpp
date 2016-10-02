/*
 * ri.cpp
 *
 *  Created on: Jul 5, 2016
 *      Author: Tomas Stibrany
 */
#include "ri.hpp"
using namespace chip8::core::cpu::registers;

IndexRegister::IndexRegister()
{
	this->registerContents = 0;
}

IndexRegister::~IndexRegister()
{
}

uint16_t IndexRegister::Read()
{
	return this->registerContents;
}

void IndexRegister::Write(uint16_t value)
{
	this->registerContents = value;
}

void IndexRegister::Increment()
{
	this->registerContents++;
}

void IndexRegister::Decrement()
{
	this->registerContents--;
}




