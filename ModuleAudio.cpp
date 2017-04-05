#include "Application.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
ModuleAudio::ModuleAudio()
{
	// TODO 5: Initialize all Music pointers to nullptr
	/*for (int i = 0; i < MAX_AUDIO; ++i)
	{
	Audio[i] = nullptr;
	}*/
	Audio[0] = nullptr;
	
}

// Destructor
ModuleAudio::~ModuleAudio()
{}

// Called before render is available
bool ModuleAudio::Init()
{
	LOG("Init Sound library");
	bool ret = true;

	// load support for the PNG image format

	int flags = MIX_INIT_OGG;

	int init = Mix_Init(flags);

	if (init & flags != flags)
	{
		LOG("Could not initialize Image lib. Mix_Init: %s", Mix_GetError());
		ret = false;
	}

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

	Audio[0] = Load("assets/Gunsmoke_06.ogg");
	SFX_shot = Mix_LoadWAV("assets/shotfx.wav");

	if (SFX_shot != nullptr)
	{
		LOG("LOADED THIS, %d",SFX_shot);
	}

	if (Mix_PlayMusic(Audio[0], -1) == -1) {
		LOG("Mix PlayMusic error: %s\n", Mix_GetError());
	}

	return ret;
}

// Called before q	uitting
bool ModuleAudio::CleanUp()
{
	LOG("Freeing Musics and Image library");

	// TODO 6: Free all Musics
	
	/*for (int i = 0; i < MAX_AUDIO; ++i)
	{
	if (Audio[i] != nullptr)
	{
	Mix_FreeMusic(Audio[i]);
	}
	}*/
	Mix_FreeMusic(Audio[0]);
	Mix_FreeChunk(SFX_shot);

	Mix_CloseAudio();

	Mix_Quit();
	return true;
}

// Load new Music from file path
Mix_Music*  ModuleAudio::Load(const char* path)
{
	// TODO 2: Load and image from a path (must be a png)
	// and check for errors

	Mix_Music * music = Mix_LoadMUS(path);
	if (music == nullptr)
	{
		LOG("Music couldn't load: %s\n", SDL_GetError());
	}
	else
	{
		LOG("Music loaded succesfully\n");
	}

	// TODO 3: Once your have the SDL_surface*, you need to create
	// a Music from it to return it (check for errors again)


	// TODO 4: Before leaving, remember to free the surface and
	// add the Music to our own array so we can properly free them

	
	/*if (last_music >= MAX_AUDIO)
	{
	LOG("Music array overflow");
	last_music = 0;
	}*/
	return music;
}
void ModuleAudio::Play_sound()
{

	//Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 2048);

	//Mix_Chunk *SFX_shot = Mix_LoadWAV("assets/shotfx.wav");
	Mix_VolumeChunk(SFX_shot, 100);

	if (SFX_shot != nullptr)
	{
		LOG("LOADED THIS, %d", SFX_shot);
	}
	if (SFX_shot == nullptr)
	{
		LOG("NOT LOADED THIS, %d",SFX_shot);
	}
	Mix_PlayChannel(1,SFX_shot,0);
	

}