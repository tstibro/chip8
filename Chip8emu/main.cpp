/*
 * chip8.cpp
 *
 *  Created on: Jul 4, 2016
 *      Author: Tomas Stibrany
 */
#include <iostream>
#include <chrono>
#include <string>

#include "../Chip8lib/Chip8.hpp"
#include "audio/audio.hpp"
#include "display/display.hpp"
#include "tinyfiledialogs/tinyfiledialogs.h"

#define EVENT_UPDATE_INTERVAL (1000 / 60)

using namespace std;
using namespace chip8;

string getBeepSoundFilePathFrom(char **argv);
SDLAudio *createSDLaudioSound(const string *pathToBeepSoundWaveFile);
SDLDisplay *createSDLdisplay(int sizeScale);
void handleInputEvent(SDL_Event event, Chip8 *emulator);
string substringBeforeLast(string str, char delimiter);

int main(int argc, char **argv)
{
	const char *chip8ROMfilePath;
	if (argc > 1)
	{
		chip8ROMfilePath = argv[1];
	}
	else
	{
		char const * fileFilter[1] = { "*.ch8" };
		chip8ROMfilePath = tinyfd_openFileDialog(
			"Choose CHIP8 ROM",
			"",
			1,
			fileFilter,
			NULL,
			0);

		if (!chip8ROMfilePath)
		{
			return -1;
		}
	}

	Chip8 *emulator = NULL;
	string beepSoundWaveFilePath = getBeepSoundFilePathFrom(argv);
	SDLAudio *audio = createSDLaudioSound(&beepSoundWaveFilePath);
	SDLDisplay *display = createSDLdisplay(10);

	if (display != nullptr)
	{
		if (audio != nullptr)
		{
			emulator = new Chip8(audio, display);
		}
		else
		{
			// Disable audio
			emulator = new Chip8(display);
		}
	}
	else
	{
		tinyfd_messageBox("Error", "Could not initialize graphics.", "ok", "error", 1);
		return -1;
	}

	display->CreateWindow("CHIP8 Emulator");
 	emulator->LoadROM(chip8ROMfilePath);

	bool isRunning = true;
	auto lastTimePoint = chrono::high_resolution_clock::now();
	long long timeAcc = 0;

	while (isRunning)
	{
		auto currentTime = chrono::high_resolution_clock::now();
		auto timeDelta = chrono::duration_cast<chrono::milliseconds>(currentTime - lastTimePoint).count();
		if (timeDelta > 0)
		{
			lastTimePoint = currentTime;
			timeAcc += timeDelta;

			if (timeAcc >= EVENT_UPDATE_INTERVAL)
			{
				timeAcc -= EVENT_UPDATE_INTERVAL;
				SDL_Event event;
				while (SDL_PollEvent(&event) > 0)
				{
					if (event.type == SDL_QUIT)
					{
						isRunning = false;
						break;
					}
					else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
					{
						handleInputEvent(event, emulator);
					}
				}
			}
		}
 		emulator->EmulateCycle(timeDelta);
	}

	delete emulator;
	delete audio;
	delete display;
	return 0;
}

string getBeepSoundFilePathFrom(char **argv)
{
	string pathToExecutable = string(argv[0]);
	string pathToFolderOfExecutable = substringBeforeLast(pathToExecutable, '\\');
	return pathToFolderOfExecutable.append("\\beepsfx.wav");
}

SDLAudio *createSDLaudioSound(const string *pathToBeepSoundWaveFile)
{
	SDLAudio *audio = nullptr;
	try
	{
		audio = new SDLAudio(pathToBeepSoundWaveFile->c_str());
	}
	catch (runtime_error e)
	{
		// Disable audio
		audio = nullptr;
	}
	return audio;
}

// Creates SDL display with default resolution of Chip8.
// sizeScale scales this resolution.
SDLDisplay *createSDLdisplay(int sizeScale)
{
	return new SDLDisplay(Chip8::GetDisplayWidth(), Chip8::GetDisplayHeight(), sizeScale);
}

string substringBeforeLast(string str, char delimiter)
{
	if (str.length() == 0) 
	{
		return str;
	}
	int lastDelimiterPosition = str.find_last_of(delimiter);
	if (lastDelimiterPosition == string::npos) {
		return str;
	}
	return str.substr(0, lastDelimiterPosition);
}

void handleInputEvent(SDL_Event event, Chip8 *emulator)
{
	bool isKeyPressed = event.key.type == SDL_KEYDOWN;
	switch (event.key.keysym.scancode)
	{
	case SDL_SCANCODE_KP_0:
		emulator->UpdateInput(0, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_1:
		emulator->UpdateInput(7, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_2:
		emulator->UpdateInput(8, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_3:
		emulator->UpdateInput(9, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_4:
		emulator->UpdateInput(4, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_5:
		emulator->UpdateInput(5, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_6:
		emulator->UpdateInput(6, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_7:
		emulator->UpdateInput(1, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_8:
		emulator->UpdateInput(2, isKeyPressed);
		break;
	case SDL_SCANCODE_KP_9:
		emulator->UpdateInput(3, isKeyPressed);
		break;
	case SDL_SCANCODE_Q:
		emulator->UpdateInput(0x0d, isKeyPressed);
		break;
	case SDL_SCANCODE_W:
		emulator->UpdateInput(0x0c, isKeyPressed);
		break;
	case SDL_SCANCODE_E:
		emulator->UpdateInput(0x0e, isKeyPressed);
		break;
	case SDL_SCANCODE_F:
		emulator->UpdateInput(0x0f, isKeyPressed);
		break;
	case SDL_SCANCODE_S:
		emulator->UpdateInput(0x0b, isKeyPressed);
		break;
	case SDL_SCANCODE_A:
		emulator->UpdateInput(0x0a, isKeyPressed);
		break;
	}
}




