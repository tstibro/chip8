/*
 * gpr.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: Tomas Stibrany
 */
#include "gpr.hpp"
using namespace chip8::core::cpu::registers;

GeneralPurposeRegister::GeneralPurposeRegister()
{
	this->registerContents = 0;
}

GeneralPurposeRegister::~GeneralPurposeRegister()
{
}

u8 GeneralPurposeRegister::Read()
{
	return this->registerContents;
}

void GeneralPurposeRegister::Write(u8 value)
{
	this->registerContents = value;
}


