#include "SDL/include/SDL.h"
#include "SDL_Image/include/SDL_image.h"
#include "SDL_Mixer/include/SDL_mixer.h"
#pragma comment (lib, "SDL/SDL2.lib")
#pragma comment (lib, "SDL/SDL2main.lib")
#pragma comment (lib, "SDL_Image/SDL2_image.lib")
#pragma comment (lib, "SDL_Mixer/SDL2_mixer.lib")
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
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC); //Creates a 2D rendering context for a window. Needs 3 parameters with those being: window where it will be rendering to, an index normally initialized to -1  and a 0 or a SDL_RendererFlags.

	if (renderer == NULL) //Upon failure to create a 2d rendering contex, the function will return NULL.
	{
		SDL_Log("Unable to create a 2D rendering context: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}
	
	//Image and textures
	SDL_Surface * surface = nullptr;

	SDL_Texture * bg_texture = nullptr;
	SDL_Texture * square_texture = nullptr;
	SDL_Texture * lazor_texture = nullptr;

	//Initializing Img
	int flags = IMG_INIT_PNG | IMG_INIT_JPG;
	int initted = IMG_Init(flags);

	if (!(IMG_Init(flags) & flags))
	{
		printf("IMG_Init: Failed to init required jpg and png support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
	}

	else
	{
		surface = SDL_GetWindowSurface(window);
	}

	//Background image
	square_texture = IMG_LoadTexture(renderer, "hadooooooken.png");
	lazor_texture = IMG_LoadTexture(renderer, "Hadouken.png");
	bg_texture = IMG_LoadTexture(renderer, "ryustage.png");

	if (surface == nullptr) 
	{
		printf("IMG_Load: %s\n", IMG_GetError());
	}

	//else
	//{
	//	/*bg_texture = SDL_CreateTextureFromSurface(renderer, surface);
	//	square_texture = SDL_CreateTextureFromSurface(renderer, surface);
	//	lazor_texture = SDL_CreateTextureFromSurface(renderer, surface);*/
	//}
	//Audio
	int mixerFlags = MIX_INIT_OGG;

	if (!(Mix_Init(mixerFlags) & mixerFlags)) //Initializes the SDL_Mixer library. Requires a flag that specifies the kind of format the audio that will be played has.
	{
		SDL_Log("Unable to initialize the SDL_Mixer library: %s\n", Mix_GetError());
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) //Initializes the Mixer API. Requires the frequency(Hz) of the audio, in which format does it come, the channels and the chunkSize.
	{
		SDL_Log("Unable to execute Mix_OpenAudio(): %s\n", Mix_GetError());
	}

	Mix_Music * music;
	music = Mix_LoadMUS("level1.ogg");

	if (!music)
	{
		SDL_Log("Mix_LoadMUS('level1.ogg'): %s\n", Mix_GetError());
	}

	Mix_Chunk * sample;
	sample = Mix_LoadWAV("laser.wav");
	
	if (!sample)
	{
		SDL_Log("Mix_LoadWAV('laser.wav'): %s\n", Mix_GetError());
	}

	if (Mix_PlayMusic(music, -1) == -1)
	{
		SDL_Log("Mix_PlayMusic: %s\n", Mix_GetError());
	}

	SDL_Rect bg = { 0, 0, 640, 480 };
	
	SDL_Rect rectangle; //Declares a structure that contains the definition of the rectangle. The origin is at the upper left.
	rectangle.x = 50; //X position of the rectangle inside the window.
	rectangle.y = 275; //Y position of the rectangle inside the window.
	rectangle.w = 150; //Width of the rectangle.
	rectangle.h = 150; //Height of the rectangle.

	SDL_Rect laser;
	laser.x = 85;
	laser.y = 290;
	laser.w = 100;
	laser.h = 50;

	bool loop = true;
	bool fire = false;

	const Uint8 * state = SDL_GetKeyboardState(NULL);

	while (loop)
	{
		SDL_Event ev;

		/*if (Mix_PlayMusic(music, 1) == -1)
		{
			SDL_Log("Mix_PlayMusic: %s\n", Mix_GetError());
		}*/

		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT)
			{
				loop = false;
			}

			if (state[SDL_SCANCODE_ESCAPE])
			{
				loop = false;
			}
			
			if (state[SDL_SCANCODE_UP])
			{
				rectangle.y -= 10;
				
				if (!fire)
				{
					laser.y -= 10;
				}
			}

			if (state[SDL_SCANCODE_DOWN])
			{
				rectangle.y += 10;

				if(state[NULL])
				{
				}
				
				if (!fire)
				{
					laser.y += 10;
				}
			}


			if (state[SDL_SCANCODE_LEFT])
			{
				rectangle.x -= 10;

				if (!fire)
				{
					laser.x -= 10;
				}
			}


			if (state[SDL_SCANCODE_RIGHT])
			{
				rectangle.x += 10;
				
				if (!fire)
				{
					laser.x += 10;
				}
			}

			if (state[SDL_SCANCODE_SPACE])
			{
				if(!sample) 
				{
					SDL_Log("Mix_LoadWav('laser.wav'): %s\n", Mix_GetError());
				}
				
				if (loop)
				{
					fire = true;
				}

				if (Mix_PlayChannel(-1, sample, 0) == -1)
				{
					SDL_Log("Mix_PlayChannel: %s\n", Mix_GetError());
				}
			}

		}

		if (fire)
		{
			laser.x += 10;

			if (laser.x > 640)
			{
				laser.x = rectangle.x + 35;
				laser.y = rectangle.y + 15;
				fire = false;
			}

		/*	if (Mix_PlayChannel(-1, sample, 0) == -1)
			{
				SDL_Log("Mix_PlayChannel: %s\n", Mix_GetError());
			}*/
		}

		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
			
		//Laser
		//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		//SDL_RenderFillRect(renderer, &laser);

		////Square
		//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		//SDL_RenderFillRect(renderer, &rectangle);

		//Sprites
		SDL_RenderCopy(renderer, bg_texture, nullptr, &bg);
		//SDL_RenderCopy(renderer, square_texture, nullptr, &rectangle);
		SDL_RenderCopy(renderer, lazor_texture, nullptr, &laser);
		SDL_RenderCopy(renderer, square_texture, nullptr, &rectangle);

		SDL_RenderPresent(renderer);

		//Audio
	
	}

	SDL_DestroyTexture(bg_texture);
	//SDL_DestroyTexture(square_texture);
	SDL_DestroyTexture(lazor_texture);
	SDL_DestroyTexture(square_texture);
	SDL_FreeSurface(surface);
	SDL_DestroyRenderer(renderer); //The SDL_DestroyRenderer destroys the rendering context and free associated textures specified in ().
	SDL_DestroyWindow(window); //The SDL_DestroyWindow function destroys the window specified in ().
	Mix_FreeChunk(sample);
	Mix_FreeMusic(music); //Frees the loaded music.
	Mix_CloseAudio(); //Shutdown and cleanup  of the Mixer API. After calling this all audio is stopped.
	Mix_Quit(); //Shutdown and cleanup of the libraries and dymanic memory space is freed.
	IMG_Quit(); //Shutdown and cleanup of the IMG subsystems and dynamic memory is freed.
	SDL_Quit(); //The SDL_Quit terminates and shuts down all subsystems.

	return 0;
}
