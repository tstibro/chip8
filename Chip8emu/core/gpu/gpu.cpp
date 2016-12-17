/*
* display.cpp
*
*  Created on: Dec 15, 2016
*      Author: Tomas Stibrany
*/
#include "gpu.hpp"

using namespace chip8::core::gpu;

GPU::GPU()
{
	ClearScreen();
}

GPU::~GPU()
{
}

void GPU::ClearScreen()
{
	for (int i = 0; i < DISPLAY_WIDTH * DISPLAY_HEIGHT; i++)
	{
		pixelMatrix[i] = 0;
	}
	refreshRequested = true;
}

u8 GPU::Draw(const u8 *spriteData, u8 dataCount, u8 x, u8 y)
{
	bool pixelFlippedFrom1to0 = false;

	for (int h = 0; h < dataCount; h++)
	{
		u8 sprite8Pixels = spriteData[h];
		// Dont forget byte of sprite data is actually 8 pixels
		for (int pixel = 0; pixel < 8; pixel++)
		{
			u8 spritePixel = (sprite8Pixels >> pixel) & 0x01;
			int xCoord = ((int)x + 7 - (int)pixel) % DISPLAY_WIDTH;
			int yCoord = ((int)y + (int)h) % DISPLAY_HEIGHT;
			u8 currentPixel = pixelMatrix[yCoord * DISPLAY_WIDTH + xCoord];
			//If any screen pixels are flipped from set to unset 1 is returned.
			pixelFlippedFrom1to0 = pixelFlippedFrom1to0 || (currentPixel == 1 && (currentPixel ^ spritePixel) == 0);
			pixelMatrix[yCoord * DISPLAY_WIDTH + xCoord] = (currentPixel ^ spritePixel) & 0x01;
		}
	}
	refreshRequested = true;
	return pixelFlippedFrom1to0 ? 1 : 0;
}

u8 GPU::GetWidth()
{
	return DISPLAY_WIDTH;
}

u8 GPU::GetHeight()
{
	return DISPLAY_HEIGHT;
}

void GPU::GetPixels(u8 *outputArray)
{
	if (outputArray == NULL)
		return;

	for (int i = 0; i < DISPLAY_WIDTH * DISPLAY_HEIGHT; i++)
	{
		outputArray[i] = pixelMatrix[i];
	}
}

bool GPU::IsRefreshRequested()
{
	return this->refreshRequested;
}

void GPU::ResetRefreshRequest()
{
	this->refreshRequested = false;
}
