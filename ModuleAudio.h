#ifndef __ModuleMusic__
#define __ModuleMusic__

#include "Module.h"
#include "ModulePlayer.h"
#include "Globals.h"
#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();
	Mix_Music* Load(const char* path);
	void Play_sound();
	//SDL_Sound* const Load(const char* path);

public:
	int last_music = 0;
	Mix_Chunk* SFX_shot = nullptr;
	Mix_Music* Audio[MAX_AUDIO];
};
#endif //__ModuleMusic__