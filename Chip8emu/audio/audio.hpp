/*
* audio.hpp
*
*  Created on: Nov 24, 2016
*      Author: Tomas Stibrany
*
*/

#ifndef IO_OUTPUT_AUDIO_HPP_
#define IO_OUTPUT_AUDIO_HPP_
#include "../../Chip8lib/adapters/audio/chip8AudioAdapter.hpp"

#include <SDL.h>
#include <SDL_mixer.h>

using namespace chip8::adapter;

class SDLAudio : public Chip8AudioAdapter
{
private:
	Mix_Chunk *sound = NULL;
public:
	SDLAudio(const char* wavFilePath);
	virtual ~SDLAudio();

	void PlaySound();

	void Stop();
};

#endif /* IO_OUTPUT_AUDIO_HPP_ */
