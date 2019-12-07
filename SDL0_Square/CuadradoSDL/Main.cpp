#pragma comment (lib, "SDL/SDL2main.lib")
#pragma comment (lib, "SDL/SDL2.lib")
#include "SDL/include/SDL.h"
#include <stdio.h>
#include <stdlib.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window * gWindow = NULL; //The window where it will be rendered.
SDL_Surface * gScreenSurface = NULL; //The surface contained in the window.
SDL_Surface  * gHelloWorld = NULL; //The image we will load and show on the screen.

bool init() //Starts up the SDL and creates a window.
{
	bool success = true; //Initialization flag.

	if (SDL_Init(SDL_INIT_VIDEO) < 0) //Initialize SDL.
	{
		printf("SDL could not be initialized. SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	else
	{
		//Creates a window.
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); //Assigns the gWindow pointer the values of the window.

		if (gWindow == NULL)
		{
			printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
			success = false;
		}

		else
		{
			//Assigns the ScreenSurface pointer the window surface parameters.
			gScreenSurface = SDL_GetWindowSurface(gWindow); //We assign the surface pointer the parameters of the surface.
		}
	}
	return success;
}

bool loadMedia() //Loads any kind of media of our choosing.
{
	bool success = true; //Loading success flag.

	gHelloWorld = SDL_LoadBMP("02_getting_an_image_on_the_screen/hello_world.bmp"); //Load splash image.

	if (gHelloWorld == NULL)
	{
		printf("Unalble to load image %s. SDL_Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

void close() //Frees the media and shuts down the SDL.
{
	SDL_FreeSurface(gHelloWorld); //Deallocates the surface.
	gHelloWorld = NULL;

	SDL_DestroyWindow(gWindow); //Eliminates the window.
	gWindow = NULL;

	SDL_Quit(); //Quit SDL subsystems.
}


int main(int argc, char*args[])
{
#if 0
	//Creates a window with a surface with the color of our choosing.
	SDL_Window * window = NULL; //The window we will be rendering to.
	SDL_Surface * screenSurface = NULL; //The surface contained in the window.

	if (SDL_Init(SDL_INIT_VIDEO) < 0) //Initialize SDL.
	{
		printf("SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
	}

	else
	{
		window = SDL_CreateWindow("SDL_Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
		}

		else
		{
			screenSurface = SDL_GetWindowSurface(window); //Asigns the surface pointer to the surface it has to show.
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00)); //Fill the surface with the color of choice.
			SDL_UpdateWindowSurface(window); //Updates the window surface.
			SDL_Delay(2000); //Wait two seconds.
		}
	}

	SDL_DestroyWindow(window); //Closes the window.
	SDL_Quit(); //Quits the SDL subsystems.
#endif

	//Starts up the SDL and creates a window:
	if (!init()) //If the bool of init returns false this compiles.
	{
		printf("Failed to initialize!\n");
	}

	else //The bool returns true so the image is loaded.
	{
		//Loads the media:
		if (!loadMedia()) //If the load media function returns false this code will be compiled.
		{
			printf("Failed to load media\n");
		}

		else
		{
			//As loadMedia returns true, the image is applied.
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

			SDL_UpdateWindowSurface(gWindow); //Updates the surface so the image is shown.
			SDL_Delay(2000); //The window holds still for 2 seconds.
		}
	}
	
	close(); //Frees resources and closes the SDL.

	return 0;
}
