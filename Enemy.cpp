#include "Enemy.h"

Enemy::Enemy(int x, int y, int s, int r) {
	posX = x;
	posY = y;
	speed = s;
	radius = r;
	LifeFlag = true;
	EnemyCount++;
};
Enemy::~Enemy() {
	EnemyCount--;
};

void Enemy::Update() {
	if(EnemyCount > 0) {
		if (LifeFlag == true) {
			posX += speed;
			if (posX > 1280) {
				speed = -(speed);
			}
			if (posX < 0) {
				speed = -(speed);
			}
		}
	}
}

void Enemy::Draw(){
	if (EnemyCount > 0) {
		Novice::DrawEllipse(posX, posY, radius, radius, 0.0f, RED, kFillModeSolid);
	}
}
