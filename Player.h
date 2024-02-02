#pragma once
#include <Novice.h>
#include "Bullet.h"

class Player
{
public:

	Player(int x,int y, int s, int r);

	void Move(char *keys,char * preKeys);
	void Draw();

	Bullet* bullet = new Bullet;

private:
	int posX;
	int posY;
	int speed;
	int radius;
};

