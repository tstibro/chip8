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

namespace chip8 { namespace io { namespace output
{
	class Display
	{
	private:
		u32 *pixelBuffer;

		int displayWidth;
		int displayHeight;
		int displayScale;

		SDL_Window *sdlWindow;
		SDL_Renderer *sdlRenderer;
		SDL_Texture *sdlTexture;
	public:
		Display(int width, int height, int scale);
		virtual ~Display();
		// Initializes SDL Window and renderer
		void CreateWindow(char *windowTitle);
		// Copies data to display's matrix. DataCount must match
		// display resolution (width * height)
		void RefreshFrom(u8 *sourceData, int dataCount);
	};

}}}




#endif /* IO_OUTPUT_DISPLAY_HPP_ */
