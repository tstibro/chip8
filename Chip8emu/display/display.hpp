/*
 * display.hpp
 *
 *  Created on: Jul 31, 2016
 *      Author: Tomas Stibrany
 */

#ifndef IO_OUTPUT_DISPLAY_HPP_
#define IO_OUTPUT_DISPLAY_HPP_
#include "../../Chip8lib/adapters/video/chip8VideoAdapter.hpp"
#include <SDL.h>

using namespace chip8::adapter;

class SDLDisplay : public Chip8VideoAdapter
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
	SDLDisplay(int width, int height, int scale);
	virtual ~SDLDisplay();
	// Initializes SDL Window and renderer
	void CreateWindow(char *windowTitle);
	// Copies data to display's matrix. DataCount must match
	// display resolution (width * height)
	void Display(u8 *sourceData, u32 dataCount);
};

#endif /* IO_OUTPUT_DISPLAY_HPP_ */
