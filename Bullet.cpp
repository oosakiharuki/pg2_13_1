#include "Bullet.h"

Bullet::Bullet() {
	posX = -100;
	posY = -100;
	speed = 20;
	radius = 20;
}

void Bullet::Update() {
	if (isBulletFlag == true) {
		posY -= speed;
	}
	if (posY < -10) {
		posY = -100;
		isBulletFlag = false;
	}
}

void Bullet::BulletFlag(int x, int y) {
	isBulletFlag = true;
	posX = x;
	posY = y;
}

void Bullet::Draw() {
	Novice::DrawEllipse(posX, posY, radius, radius, 0.0f, BLUE, kFillModeSolid);
}