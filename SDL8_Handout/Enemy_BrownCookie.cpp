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

	original_y = y;
}

void Enemy_BrownCookie::Move()
{
	//fPoint position(1, 1);
	/*if (going_up)
	{
		if (wave > 6.0f)
			going_up = false;
		else
			wave += 0.05f;
	}
	else
	{
		if (wave < -6.0f)
			going_up = true;
		else
			wave -= 0.05f;
	}

	position.y = int(float(original_y) + (25.0f * sinf(wave)));*/
	path.PushBack(steps.speed, steps.frames, steps.animation);
	//position.y = original_pos.y + path.GetCurrentPosition();
	position.x -= 1;
}
