#pragma once
#include <Novice.h>
class Bullet
{
public:

	Bullet();
	void Update();
	void BulletFlag(int x, int y);
	void Draw();

	int GetPosX() { return posX; }
	int GetPosY() { return posY; }
	int GetSpeed() { return speed; }
	int GetRadius() { return radius; }
	int GetBulletFlag() { return isBulletFlag; }

private:
	int posX;
	int posY;
	int speed;
	int radius;
	bool isBulletFlag;
};

