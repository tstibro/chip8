/*
* gpu.hpp
*
*  Created on: Dec 15, 2016
*      Author: Tomas Stibrany
*/

#ifndef CORE_GPU_HPP_
#define CORE_GPU_HPP_
#include "../../chip8Types.hpp"

#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32

namespace chip8 {
	namespace core {
		namespace gpu
		{
			class GPU
			{
			private:
				u8 pixelMatrix[DISPLAY_HEIGHT * DISPLAY_WIDTH];
				bool refreshRequested;
			public:
				GPU();
				~GPU();

				void ClearScreen();
				// Draw sprite by writing data to pixel buffer
				// If any screen pixels are flipped from set to unset 1 is returned.
				// Otherwise 0 is returned
				u8 Draw(const u8 *spriteData, u8 dataCount, u8 x, u8 y);
				// Returns width of the screen
				u8 GetWidth();
				// Return height of the screen
				u8 GetHeight();

				// Copies pixels to outputArray. Array must be of size at least width*height.
				// This is used to interface with external classes which render the pixels to screen
				void GetPixels(u8 *outputArray);
				// Returns true when screen data have changed. Use it to
				// check whether rendering to screen is necessary.
				bool IsRefreshRequested();
				// Resets resfresh request flag
				void ResetRefreshRequest();
			};
		}
	}
}

#endif /* CORE_GPU_HPP_ */
