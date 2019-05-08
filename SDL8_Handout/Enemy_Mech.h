#ifndef __ENEMY_BROWNCOOKIE_H__
#define __ENEMY_BROWNCOOKIE_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Mech : public Enemy
{
private:
	bool going_up = true;
	fPoint speed;
	uint frames;
	iPoint original_pos;
	Animation fly;
	Path path;

public:

	Enemy_Mech(int x, int y);

	void Move();
};

#endif // __ENEMY_BROWNCOOKIE_H__#pragma once
