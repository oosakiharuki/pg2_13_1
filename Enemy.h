#pragma once
#include<Novice.h>
class Enemy
{
protected:
public:
	static int EnemyCount;
	Enemy(int x, int y, int s, int r);
	~Enemy();
	void Update();
	void Draw();

	int GetPosX() { return posX; }
	int GetPosY() { return posY; }
	int GetSpeed() { return speed; }
	int GetRadius() { return radius; }
	int GetLifeFlag() { return radius; }

private:
	int posX;
	int posY;
	int speed;
	int radius;
	bool LifeFlag;
	int hp;
}; 

