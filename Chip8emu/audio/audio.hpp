/*
* audio.hpp
*
*  Created on: Nov 24, 2016
*      Author: Tomas Stibrany
*
*  This code is based on: https://gist.github.com/armornick/3447121
*/

#ifndef IO_OUTPUT_AUDIO_HPP_
#define IO_OUTPUT_AUDIO_HPP_
#include "../chip8Types.hpp"
#include <SDL.h>
#include <SDL_mixer.h>

namespace chip8 {
	namespace io {
		namespace output
		{
			class Audio
			{
			private:
				Mix_Chunk *sound = NULL;
			public:
				Audio(char* wavFilePath);
				virtual ~Audio();

				void Play();

				void Stop();
			};

		}
	}
}




#endif /* IO_OUTPUT_AUDIO_HPP_ */
