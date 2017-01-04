/*
* chip8AudioInterface.hpp
*
*  Created on: Jan 2, 2017
*      Author: Tomas Stibrany
*/

#ifndef CHIP8_AUDIO_INTERFACE_HPP_
#define CHIP8_AUDIO_INTERFACE_HPP_

#ifdef CHIP8LIB_EXPORTS  
#define CHIP8LIB_API __declspec(dllexport)   
#else  
#define CHIP8LIB_API __declspec(dllimport)   
#endif 

namespace chip8 {
	namespace adapter {
		// Adapter through Chip8 emulator emits sound
		class CHIP8LIB_API Chip8AudioAdapter
		{
		public:
			Chip8AudioAdapter();
			virtual ~Chip8AudioAdapter();
			virtual void PlaySound() = 0;
		};
	}
}
#endif
