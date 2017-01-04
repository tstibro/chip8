/*
* chip8VideoInterface.hpp
*
*  Created on: Jan 2, 2017
*      Author: Tomas Stibrany
*/

#ifndef CHIP8_VIDEO_ADAPTER_HPP_
#define CHIP8_VIDEO_ADAPTER_HPP_

#include "../../chip8Types.hpp"

#ifdef CHIP8LIB_EXPORTS  
#define CHIP8LIB_API __declspec(dllexport)   
#else  
#define CHIP8LIB_API __declspec(dllimport)   
#endif 


namespace chip8 {
	namespace adapter {
		// Adapter through Chip8 emulator displays graphical data
		class CHIP8LIB_API Chip8VideoAdapter
		{
		public:
			Chip8VideoAdapter();
			virtual ~Chip8VideoAdapter();
			// Display provided graphics data
			// Color depth is 1-bit. 1 Byte = 1 pixel
			virtual void Display(u8 *chip8graphicalData, u32 byteCount) = 0;
		};
	}
}
#endif

