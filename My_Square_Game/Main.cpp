#include "SDL/include/SDL.h"
#include "SDL_Image/include/SDL_image.h"
#pragma comment (lib, "SDL/SDL2.lib")
#pragma comment (lib, "SDL/SDL2main.lib")
#pragma comment (lib, "SDL_Image/SDL2_Image.lib")
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char * argv[])
{

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) //SDL_Init returns 0 on success. This function initializes the SDL.
	{
		SDL_Log("Unable to initialize: %s\n", SDL_GetError()); //The SDL_GetError function returns the error number of whatever has made the SDL fail to initialize.
		SDL_Quit();
		return 1;
	}

	SDL_Window * window = NULL; //SDL_Window declares a pointer which is related to creating windows.

	//SDL_CreateWindow creates a window by using 6 parameters: Name of the window, x and y position of the window on screen, horizontal and vertical size of the window and at last a 0 or SDL_WindowFlags.
	window = SDL_CreateWindow("Square Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (window == NULL) //Upon failure to create a window (assigning a value to the pointer in this case) the function will retrun NULL.
	{
		SDL_Log("Unable to create a window: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_Renderer * renderer = NULL; //Contains a rendered state.
	renderer = SDL_CreateRenderer(window, -1, 0); //Creates a 2D rendering context for a window. Needs 3 parameters with those being: window where it will be rendering to, an index normally initialized to -1  and a 0 or a SDL_RendererFlags.

	if (renderer == NULL) //Upon failure to create a 2d rendering contex, the function will return NULL.
	{
		SDL_Log("Unable to create a 2D rendering context: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_Rect rectangle; //Declares a structure that contains the definition of the rectangle. The origin is at the upper left.
	rectangle.x = 290; //X position of the rectangle inside the window.
	rectangle.y = 185; //Y position of the rectangle inside the window.
	rectangle.w = 75; //Width of the rectangle.
	rectangle.h = 75; //Height of the rectangle.

	SDL_Rect laser;
	laser.x = 375;
	laser.y = 210;
	laser.w = 30;
	laser.h = 10;

	bool loop = true;
	bool quit = true;
	bool fire = false;

	int rectvelx = 0;
	int rectvely = 0;

	while (loop)
	{
#if 0
		if (rectangle.x > 565)
		{
			loop = false;
		}

		else if (rectangle.x < 0)
		{
			loop = true;
		}
#endif
		const Uint8 * state = SDL_GetKeyboardState(NULL);

		while (loop)
		{
			SDL_Event ev;

			while (SDL_PollEvent(&ev))
			{
				if (ev.type == SDL_QUIT)
				{
					loop = false;
				}

				else if (ev.type == SDL_KEYDOWN)
				{
					switch (ev.key.keysym.sym)
					{
					case SDLK_UP:
						if (rectangle.y < 0)
						{
							break;
						}
						rectangle.y -= 10;
						laser.y -= 10;
						break;

					case SDLK_DOWN:
						if (rectangle.y > 400)
						{
							break;
						}
						rectangle.y += 10;
						laser.y += 10;
						break;

					case SDLK_LEFT:
						if (rectangle.x < 0)
						{
							break;
						}

						rectangle.x -= 10;
						laser.x -= 10;
						break;

					case SDLK_RIGHT:
						if (rectangle.x > 575)
						{
							break;
						}
						rectangle.x += 10;
						laser.x += 10;
						break;

					case SDLK_ESCAPE:
						loop = false;
						break;

					case SDLK_SPACE:
#if 0
						while (quit)
						{
							if (laser.x < 640)
							{
								laser.x++;

							}

							else if (laser.x >= 640)
							{
								laser.x = 325;
								break;
							}
#endif
							if (quit)
							{
								laser.x = 290;
								laser.y = 200;
								fire = true;
							}

							/*SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
							SDL_RenderFillRect(renderer, &laser);
							SDL_RenderPresent(renderer);*/
					}
						break;

					///*case SDLK_7:
					//	rectvelx++;
					//	rectvely++;*/

					//	while (quit)
					//	{
					//		rectangle.x += rectvelx;
					//		rectangle.y += rectvely;
					//	}
					//	break;
				}
			}

			if (fire)
			{
				laser.x += 10;
				
				if (fire > 640)
				{
					fire == false;
				}
			}
					

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			SDL_RenderFillRect(renderer, &laser);
			SDL_RenderPresent(renderer);

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &rectangle);
			SDL_RenderPresent(renderer);
			SDL_Delay(16);
		}
#if 0
			if (loop)
			{
				rectangle.x++;
			}

			else
			{
				rectangle.x--;
			}
#endif
	}

	SDL_DestroyRenderer(renderer); //The SDL_DestroyRenderer destroys the rendering context and free associated textures specified in ().
	SDL_DestroyWindow(window); //The SDL_DestroyWindow function destroys the window specified in ().
	SDL_Quit(); //The SDL_Quit terminates and shuts down all subsystems.

	return 0;
}
