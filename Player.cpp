#include "Player.h"

Player::Player(int x, int y,int s, int r) {
	posX = x;
	posY = y;
	speed = s;
	radius = r;
}

void Player::Move(char* keys, char* preKeys) {
	if (keys[DIK_A] && preKeys[DIK_A]){
		posX -= speed;
	}
	if (keys[DIK_D] && preKeys[DIK_D]) {
		posX += speed;
	}
	if (keys[DIK_W] && preKeys[DIK_W]) {
		posY -= speed;
	}
	if (keys[DIK_S] && preKeys[DIK_S]) {
		posY += speed;
	}
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && bullet->GetBulletFlag() == false) {
		bullet->BulletFlag(posX,posY);
	}
	bullet->Update();
}

void Player::Draw() {
	Novice::DrawEllipse(posX, posY, radius, radius, 0.0f, GREEN, kFillModeSolid);
	bullet->Draw();
}