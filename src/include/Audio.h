#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

class Audio
{
public:
	Audio();
	~Audio();
	
	void load(const char* path);
	void play();

private:
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;
	SDL_AudioDeviceID deviceID;
};
