/*
 * delayTimer.hpp
 *
 *  Created on: Jul 17, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_TIMERS_TIMER_HPP_
#define CORE_CPU_TIMERS_TIMER_HPP_
#include "../../../chip8Types.hpp"

#define TIMER_FREQ 60

namespace chip8 { namespace core { namespace cpu { namespace timers
{

	class Timer
	{
	private:
		u8 value;
	public:
		Timer();
		~Timer();

		void SetValue(u8 value);
		u8 GetValue();

		void Tick();
	};

}}}}




#endif /* CORE_CPU_TIMERS_TIMER_HPP_ */
