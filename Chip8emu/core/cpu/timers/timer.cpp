/*
 * delayTimer.cpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */
#include "timer.hpp"

using namespace chip8::core::cpu::timers;

Timer::Timer()
{
	this->value = 0;
}

Timer::~Timer()
{

}

void Timer::SetValue(u8 value)
{
	this->value = value;
}

u8 Timer::GetValue()
{
	return this->value;
}

void Timer::Tick()
{
	if (this->value > 0)
		this->value--;
}



