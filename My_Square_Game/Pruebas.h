#pragma once
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