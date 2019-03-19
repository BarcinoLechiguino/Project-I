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

// TODO 4: Finally create a screen surface and keep it as a public variable
SDL_Surface * surface = nullptr;

//Renderer
SDL_Renderer * renderer = nullptr;

int loop = LOOP_OGN;

bool ModuleWindow::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		LOG("Unable to initialize SDL library: %s\n", SDL_GetError());
		SDL_Quit();
	}

	// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
// then create the window and check for errors
	else
	{
		window = SDL_CreateWindow("HandoutII", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

		if (window == nullptr)
		{
			LOG("Unable to initialize window: %s\n", SDL_GetError());
			SDL_Quit();
		}

		surface = SDL_GetWindowSurface(window);

		if (surface == nullptr)
		{
			LOG("Unable to create a surface on window: %s\n", SDL_GetError());
			SDL_Quit();
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

		if (renderer = nullptr)
		{
			LOG("Unable to create a surface on window: %s\n", SDL_GetError());
			SDL_Quit();
		}
		
		else
		{
			while (loop == LOOP_OGN)
			{
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderClear(renderer);

			}
			SDL_DestroyRenderer(renderer);
		}
	}
	
	return true;
}

bool ModuleWindow::CleanUp()
{
	if (ModuleWindow::Init() == true)
	{
		SDL_FreeSurface(surface);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	
	return false;
}

// TODO 5: Fill with code CleanUp() method :)

