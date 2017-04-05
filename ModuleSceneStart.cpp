#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneStart.h"
#include "ModuleInput.h"
#include "ModuleSceneSpace.h"
#include "ModuleFadeToBlack.h"

ModuleSceneStart::ModuleSceneStart()
{}

ModuleSceneStart::~ModuleSceneStart()
{}

bool ModuleSceneStart::Start()
{
	LOG("Loading start scene");

	intro = App->textures->Load("assets/start.png");

	return true;
}
// Update: draw background
update_status ModuleSceneStart::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(intro, 0, 0, NULL);
	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack(this,App->scene_space,1.0f);
	}
	return UPDATE_CONTINUE;
}

bool ModuleSceneStart::CleanUp()
{
	LOG("Unloading start scene");

	App->textures->Unload(intro);

	return true;
}
