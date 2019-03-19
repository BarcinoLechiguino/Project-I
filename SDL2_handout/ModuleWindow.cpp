#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"

#include "SDL/include/SDL.h" //Added from Main.cpp
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )


// TODO 2: Init the library and check for possible error
// using SDL_GetError()

//int ModuleWindow::method() //Defines a method.
//{
//	return 23;
//}

SDL_Window * window = nullptr;

bool ModuleWindow::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		LOG("Unable to initialize SDL library: %s\n", SDL_GetError());
		SDL_Quit();
	}

	else
	{
		window = SDL_CreateWindow("HandoutII", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 960, SDL_WINDOW_RESIZABLE);

		if (window == nullptr)
		{
			LOG("Unable to initialize window: %s\n", SDL_GetError());
			SDL_Quit();
		}
	}
	
	return true;
}

bool ModuleWindow::CleanUp()
{
	return false;
}

// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
// then create the window and check for errors

// TODO 4: Finally create a screen surface and keep it as a public variable

// TODO 5: Fill with code CleanUp() method :)

