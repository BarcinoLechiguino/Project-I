#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneSpace.h"
#include "ModuleIntroScene.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleIntroScene::ModuleIntroScene()
{}

ModuleIntroScene::~ModuleIntroScene()
{}

// Load assets
bool ModuleIntroScene::Start()
{
	LOG("Loading Intro scene");

	intro = App->textures->Load("rtype/intro.png");

	return true;
}

// UnLoad assets
bool ModuleIntroScene::CleanUp()
{
	LOG("Unloading Intro scene");

	App->textures->Unload(intro);

	return true;
}

// Update: draw background
update_status ModuleIntroScene::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(intro, 0, 0, NULL);
	if (App->input->keyboard[SDL_SCANCODE_E] == 1) {

		App->fade->FadeToBlack(App->intro, App->scene_space, 2.5f);

	}

	return UPDATE_CONTINUE;
}