#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleIntroScene.h"
#include "ModuleSceneSpace.h"
#include "ModuleFadeToBlack.h"


ModuleIntroScene::ModuleIntroScene()
{}

ModuleIntroScene::~ModuleIntroScene()
{}

// Load assets
bool ModuleIntroScene::Start()
{
	LOG("Loading intro scene");

	intro = App->textures->Load("rtype/intro.png");

	App->player->Disable();

	return true;
}

// UnLoad assets
bool ModuleIntroScene::CleanUp()
{
	LOG("Unloading intro scene");

	App->textures->Unload(intro);

	return true;
}

// Update: draw background
update_status ModuleIntroScene::Update()
{
	if (App->input->keyboard[SDL_SCANCODE_SPACE])
	{
		App->fade->FadeToBlack(App->intro_scene, App->scene_space, 2.0f);
	}
	// Draw everything --------------------------------------
	App->render->Blit(intro, 0, 0, NULL);

	return UPDATE_CONTINUE;
}
