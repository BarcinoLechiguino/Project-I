#pragma comment (lib, "SDL/SDL2main.lib")
#pragma comment (lib, "SDL/SDL2.lib")
#include "SDL/include/SDL.h"
#include <stdio.h>
#include <stdlib.h>

//Screen proportions:
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char*args[])
{
	SDL_Window * window = NULL; //The window we'll be rendering to.
	SDL_Surface * screenSurface = NULL; //The surface contained in the window.
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) //Initialize SDL.
	{
		printf("SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
	}

	
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			printf("Window could not be created. SDL Error: %s\n", SDL_GetError());
		}

		
		else
		{
			screenSurface = SDL_GetWindowSurface(window); //Get window surface.

			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF)); // Fill the surface with the white color.

			SDL_UpdateWindowSurface(window); //Update the surface.

			SDL_Delay(2000); //Wait two seconds.
		}

	}

	SDL_DestroyWindow(window); // Destroy Window.

	SDL_Quit(); //Quit SDL subsystems.

	return 0;
}


