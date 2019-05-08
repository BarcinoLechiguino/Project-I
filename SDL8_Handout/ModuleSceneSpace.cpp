#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
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
	
	background = App->textures->Load("rtype/background.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	// Colliders ---
	App->collision->AddCollider({0, 224, 3930, 16}, COLLIDER_WALL);
	App->collision->AddCollider({1375, 0, 111, 96}, COLLIDER_WALL);
	App->collision->AddCollider({1375, 145, 111, 96}, COLLIDER_WALL);

	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 600, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 625, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 640, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 665, 80);
	
	// TODO 1: Add a new wave of red birds
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 725, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 750, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 765, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::REDBIRD, 790, 140);

	//TODO 2: Add a wave of brown cookies
	App->enemies->AddEnemy(ENEMY_TYPES::BROWNCOOKIE, 850, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWNCOOKIE, 865, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWNCOOKIE, 880, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWNCOOKIE, 895, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWNCOOKIE, 910, 100);

	App->enemies->AddEnemy(ENEMY_TYPES::BROWNCOOKIE, 950, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWNCOOKIE, 965, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWNCOOKIE, 980, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWNCOOKIE, 995, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::BROWNCOOKIE, 1010, 140);

	//TODO 3: Add a Mech walking
	App->enemies->AddEnemy(ENEMY_TYPES::MECH, 825, 160);
	
	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

 	App->textures->Unload(background);

	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	App->render->camera.x += 1 * SCREEN_SIZE;

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);
	
	return UPDATE_CONTINUE;
}