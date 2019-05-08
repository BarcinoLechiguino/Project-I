#include "Application.h"
#include "Enemy_BrownCookie.h"
#include "ModuleCollision.h"
#include "Path.h"

Enemy_BrownCookie::Enemy_BrownCookie(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 5,72,21,22 });
	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos = position;

	path.PushBack({ -1, -1 }, 80, &fly);
	path.PushBack({ -1, 1 }, 80, &fly);
	path.PushBack({ -1, -1 }, 80, &fly);
	path.PushBack({ -1, 1 }, 80, &fly);
}



void Enemy_BrownCookie::Move()
{
	position = original_pos + path.GetCurrentPosition();
}
