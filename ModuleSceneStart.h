#ifndef _MODULESCENESTART_H_
#define	_MODULESCENESTART_H_

#include "Module.h"

struct SDL_Texture;

class ModuleSceneStart : public Module
{
public:
	ModuleSceneStart();
	~ModuleSceneStart();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* intro;
};
#endif //_MODULESCENESTART_H_
