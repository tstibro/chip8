/*
 * display.cpp
 *
 *  Created on: Jul 31, 2016
 *      Author: Tomas Stibrany
 */
#include "display.hpp"
#include <stdexcept>

using namespace std;
using chip8::io::output::Display;

Display::Display(int width, int height, int scale)
{
	sdlWindow = 0;
	sdlRenderer = 0;

	displayWidth = width;
	displayHeight = height;
	displayScale = scale;

	pixelBuffer = new u32[displayWidth * displayHeight];
	for (int i = 0; i < displayWidth * displayHeight; i++)
	{
		pixelBuffer[i] = 0;
	}
}

Display::~Display()
{
	delete pixelBuffer;
	SDL_DestroyTexture(sdlTexture);
	SDL_DestroyRenderer(sdlRenderer);
	SDL_DestroyWindow(sdlWindow);
	SDL_Quit();
}

void Display::CreateWindow(char *windowTitle)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		throw runtime_error(string("SDL_Init Error: ") + SDL_GetError());
	}

	sdlWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, displayWidth * displayScale, displayHeight * displayScale, SDL_WINDOW_SHOWN);
	if (sdlWindow == nullptr){
		const char *sdlError = SDL_GetError();
		SDL_Quit();
		throw runtime_error(string("SDL_CreateWindow Error: ") + sdlError);
	}

	sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
	if (sdlRenderer == nullptr)
	{
		const char *sdlError = SDL_GetError();
		SDL_Quit();
		throw runtime_error(string("SDL_CreateRenderer Error: ") + sdlError);
	}
	SDL_RenderSetLogicalSize(sdlRenderer, displayWidth * displayScale, displayHeight * displayScale);

	sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING, displayWidth, displayHeight);
	if (sdlRenderer == nullptr)
	{
		const char *sdlError = SDL_GetError();
		SDL_Quit();
		throw runtime_error(string("SDL_CreateTexture Error: ") + sdlError);
	}
}

void Display::RefreshFrom(u8 *sourceData, int dataCount)
{
	if (dataCount != displayWidth * displayHeight)
		return;

	for (int i = 0; i < dataCount; i++)
	{
		pixelBuffer[i] = (0x00FFFFFF * (u32)sourceData[i]) | 0xFF000000;
	}
	SDL_UpdateTexture(sdlTexture, NULL, pixelBuffer, displayWidth * sizeof(Uint32));
	// Clear screen and render
	SDL_RenderClear(sdlRenderer);
	SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
	SDL_RenderPresent(sdlRenderer);
}



