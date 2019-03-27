#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// Background / sky
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	//Ship
	ship.x = 8;
	ship.y = 20;
	ship.w = 525;
	ship.h = 200;

	// flag animation
	flag.PushBack({848, 208, 40, 40});
	flag.PushBack({848, 256, 40, 40});
	flag.PushBack({848, 304, 40, 40});
	flag.speed = 0.08f;

	//Woman animation
	woman.PushBack({ 624, 16, 32, 54 });
	woman.PushBack({ 624, 80, 32, 54 });
	woman.PushBack({ 624, 144, 32, 54 });
	woman.PushBack({ 624, 80, 32, 54 });
	woman.speed = 0.1f;
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("ken_stage.png");
	return ret;
}

float timer = 0.0f;
bool up = true;

// Update: draw background
update_status ModuleBackground::Update()
{
	if ((int)timer == -5) { up = true; }
	if ((int)timer == 0) { up = false; }
	
	if (up) { timer += 0.05f; }
	if (!up) { timer -= 0.05f; }

	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &background, 0.75f); // sea and sky
	App->render->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), 0.75f); // flag animation

	// TODO 2: Draw the ship from the sprite sheet with some parallax effect
	App->render->Blit(graphics, 0, timer, &ship, 0.95f); //The ship
	

	// TODO 3: Animate the girl on the ship (see the sprite sheet)
	App->render->Blit(graphics, 192, 109 + timer, &(woman.GetCurrentFrame()), 0.75f); //Woman animation

	App->render->Blit(graphics, 0, 170, &ground);

	return UPDATE_CONTINUE;
}