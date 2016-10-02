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

Display::Display()
{
	sdlWindow = 0;
	sdlRenderer = 0;
	for (int y = 0; y < DISPLAY_HEIGHT; y++)
	{
		for (int x = 0; x < DISPLAY_WIDTH; x++)
		{
			this->pixelBuffer[y * DISPLAY_WIDTH + x] = 0;
			this->pixelMatrix[y * DISPLAY_WIDTH + x] = 0;
		}
	}
}

Display::~Display()
{
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

	sdlWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DISPLAY_WIDTH * DISPLAY_WINDOW_SCALE, DISPLAY_HEIGHT * DISPLAY_WINDOW_SCALE, SDL_WINDOW_SHOWN);
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
	SDL_RenderSetLogicalSize(sdlRenderer, DISPLAY_WIDTH * DISPLAY_WINDOW_SCALE, DISPLAY_HEIGHT * DISPLAY_WINDOW_SCALE);

	sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	if (sdlRenderer == nullptr)
	{
		const char *sdlError = SDL_GetError();
		SDL_Quit();
		throw runtime_error(string("SDL_CreateTexture Error: ") + sdlError);
	}
}

void Display::ClearScreen()
{
	for(int y = 0; y < DISPLAY_HEIGHT; y++)
	{
		for (int x = 0; x < DISPLAY_WIDTH; x++)
		{
			pixelBuffer[y * DISPLAY_WIDTH + x] = 0;
		}
	}
	SDL_UpdateTexture(sdlTexture, NULL, pixelBuffer, 64 * sizeof(Uint32));
	// Clear screen and render
	SDL_RenderClear(sdlRenderer);
	SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
	SDL_RenderPresent(sdlRenderer);
}

void Display::Refresh()
{
	for (int y = 0; y < DISPLAY_HEIGHT; y++)
	{
		for (int x = 0; x < DISPLAY_WIDTH; x++)
		{
			pixelBuffer[y * DISPLAY_WIDTH + x] = (0x00FFFFFF * pixelMatrix[y * DISPLAY_WIDTH + x]) | 0xFF000000;
		}
	}
	SDL_UpdateTexture(sdlTexture, NULL, pixelBuffer, DISPLAY_WIDTH * sizeof(Uint32));
	// Clear screen and render
	SDL_RenderClear(sdlRenderer);
	SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
	SDL_RenderPresent(sdlRenderer);
}

u8 Display::Draw(const u8 *spriteData, u8 spriteWidth, u8 spriteHeight, u8 x, u8 y)
{
	bool pixelFlippedFrom1to0 = false;

	for (int h = 0; h < spriteHeight; h++)
	{
		for (int w = 0; w < spriteWidth; w++)
		{
			u8 sprite8Pixels = spriteData[h * spriteWidth + w];
			// Dont forget byte of sprite data is actually 8 pixels
			for (int pixel = 0; pixel < 8; pixel++)
			{
				u8 spritePixel = (sprite8Pixels >> pixel) & 0x01;
				int xCoord = ((int)x + 7 - (int)pixel + ((int)w * 8)) % DISPLAY_WIDTH;
				int yCoord = ((int)y + ((int)h * (int)spriteWidth)) % DISPLAY_HEIGHT;
				u8 currentPixel = pixelMatrix[yCoord * DISPLAY_WIDTH + xCoord];
				//If any screen pixels are flipped from set to unset 1 is returned.
				pixelFlippedFrom1to0 = pixelFlippedFrom1to0 || (currentPixel == 1 && spritePixel == 0);
				pixelMatrix[yCoord * DISPLAY_WIDTH + xCoord] = currentPixel ^ spritePixel;
			}
		}
	}
	return pixelFlippedFrom1to0 ? 1 : 0;
}



