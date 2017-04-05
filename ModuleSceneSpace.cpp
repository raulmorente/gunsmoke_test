#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleSceneSpace.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace()
{}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("assets/map1.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	
	// Colliders ---

	Wall[0] = App->collision->AddCollider({ 116, 60,24, 22 }, COLLIDER_WALL); // POZO Nº1

	Wall[1] = App->collision->AddCollider({ 0, -165/*2688*/, 68 ,340 }, COLLIDER_WALL); //EDIFICIO A
	//Wall[2] = App->collision->AddCollider({ 0, 0/*3038*/, 29, 19 }, COLLIDER_WALL); 

	Wall[2] = App->collision->AddCollider({ 160, -783, 68, 700 }, COLLIDER_WALL); // EDIFICIO B

	//ESCALERAS DERECHA
	Wall[3] = App->collision->AddCollider({ 149, -238, 11, 19 }, COLLIDER_WALL); // ESCALERA A

	Wall[4] = App->collision->AddCollider({ 149, -335, 11, 19 }, COLLIDER_WALL); // ESCALERA B

	Wall[5] = App->collision->AddCollider({ 149, -432, 11, 19 }, COLLIDER_WALL); // ESCALREA C

	Wall[6] = App->collision->AddCollider({ 149, -494, 11, 19 }, COLLIDER_WALL); // ESCALERA D

	Wall[7] = App->collision->AddCollider({ 149, -591, 11, 19 }, COLLIDER_WALL); // ESCALERA E

	Wall[8] = App->collision->AddCollider({ 149, -688, 11, 19 }, COLLIDER_WALL); // ESCALERA F

	//ESCALERAS DE LA IZQUIERDA
	Wall[9] = App->collision->AddCollider({ 68, 18, 11, 19 }, COLLIDER_WALL); // ESCALERA A

	Wall[10] = App->collision->AddCollider({ 68, 112, 11, 19 }, COLLIDER_WALL); // ESCALERA A

	Wall[11] = App->collision->AddCollider({ 68, -45, 11, 19 }, COLLIDER_WALL); // ESCALERA A

	Wall[12] = App->collision->AddCollider({ 68, -143, 11, 19 }, COLLIDER_WALL); // ESCALERA A

	/*x=
  68  y=2972  w=11  h=19
x=68  y=2876  w=11  h=19
x=68  y=2812  w=11  h=19
x=68  y=2715  w=11  h=19*/

	Enemy = App->collision->AddCollider({ 97,-970,30, 29 }, COLLIDER_ENEMY);
	// TODO 1: Add colliders for the first columns of the level

	return true;
}
// done faltan las escaleras :D
// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

 	App->textures->Unload(background);
	App->player->Disable();
	App->collision->Disable();
	App->particles->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	int scroll_speed = 1;

	App->player->position.y -= 1;
	App->render->camera.y += 2;
	

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, -2860, NULL);
	
	return UPDATE_CONTINUE;
}