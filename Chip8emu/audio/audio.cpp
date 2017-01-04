/*
* display.cpp
*
*  Created on: Nov 24, 2016
*      Author: Tomas Stibrany
*/
#include "audio.hpp"
#include <stdexcept>

using namespace std;

SDLAudio::SDLAudio(char *wavFilePath)
{
	if (SDL_Init(SDL_INIT_AUDIO) != 0) {
		throw runtime_error(string("SDL_Init Error: ") + SDL_GetError());
	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) != 0)
	{
		throw runtime_error(string("Mix_OpenAudio Error"));
	}

	sound = Mix_LoadWAV(wavFilePath);
	if (sound == NULL)
	{
		throw runtime_error(string("Mix_LoadWAV Error"));
	}
}

SDLAudio::~SDLAudio()
{
	Mix_FreeChunk(sound);
	//Quit SDL_mixer
	Mix_CloseAudio();
}

void SDLAudio::PlaySound()
{
	if (Mix_PlayingMusic() == 0)
	{
		Mix_PlayChannel(-1, sound, 0);
	}
}

void SDLAudio::Stop()
{
	Mix_HaltMusic();
}
