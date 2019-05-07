#ifndef __ENEMY_BROWNCOOKIE_H__
#define __ENEMY_BROWNCOOKIE_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_BrownCookie : public Enemy
{
private:
	float wave = -4.0f;
	bool going_up = true;
	int original_y = 0;
	fPoint speed;
	uint frames;
	iPoint original_pos;
	Animation fly;
	Path path;
	Step steps;

public:

	Enemy_BrownCookie(int x, int y);

	void Move();
};

#endif // __ENEMY_REDBIRD_H__