/*
 * display.hpp
 *
 *  Created on: Jul 31, 2016
 *      Author: Tomas Stibrany
 */

#ifndef IO_OUTPUT_DISPLAY_HPP_
#define IO_OUTPUT_DISPLAY_HPP_
#include "../chip8Types.hpp"
#include <SDL.h>

#define DISPLAY_WIDTH 64
#define DISPLAY_HEIGHT 32
#define DISPLAY_WINDOW_SCALE 10

namespace chip8 { namespace io { namespace output
{

	class Display
	{
	private:
		u8 pixelMatrix[DISPLAY_HEIGHT * DISPLAY_WIDTH];
		u32 pixelBuffer[DISPLAY_HEIGHT * DISPLAY_WIDTH];

		SDL_Window *sdlWindow;
		SDL_Renderer *sdlRenderer;
		SDL_Texture *sdlTexture;

		bool shouldRefresh;
	public:
		Display();
		virtual ~Display();
		// Initializes SDL Window and renderer
		void CreateWindow(char *windowTitle);
		// Clears color bits in pixel buffer
		void ClearScreen();
		// Copies data from buffer to matrix
		void Refresh();
		// Draw sprite by writing data to pixel buffer
		// If any screen pixels are flipped from set to unset 1 is returned.
		// If that does not happen, 0 is returned
		u8 Draw(const u8 *spriteData,u8 spriteHeight, u8 x, u8 y);
	};

}}}




#endif /* IO_OUTPUT_DISPLAY_HPP_ */
