#ifndef __MODULEINTROSCENE_H__
#define __MODULEINTROSCENE_H__

#include "Module.h"

class ModuleIntroScene : public Module
{
public:
	ModuleIntroScene();
	~ModuleIntroScene();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* intro = nullptr;
};

#endif // __MODULEINTROSCENE_H__