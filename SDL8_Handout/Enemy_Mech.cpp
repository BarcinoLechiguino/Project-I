#include "Application.h"
#include "Enemy_Mech.h"
#include "ModuleCollision.h"
#include "Path.h"

Enemy_Mech::Enemy_Mech(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 6, 108, 30, 28});
	fly.PushBack({ 5,72,21,22 });
	/*fly.PushBack({ 5,72,21,22 });
	fly.PushBack({ 5,72,21,22 });
	fly.PushBack({ 5,72,21,22 });
	fly.PushBack({ 5,72,21,22 });*/
	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos = position;

	path.PushBack({ -1, 0 }, 80, &fly);
	path.PushBack({ -1, 0 }, 80, &fly);
}



void Enemy_Mech::Move()
{
	position = original_pos + path.GetCurrentPosition();
}
