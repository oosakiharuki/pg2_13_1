#include <Novice.h>
#include<iostream>
#include "Player.h"
#include "Enemy.h"
using namespace std;

const char kWindowTitle[] = "LC1B_03_オオサキ_ハルキ_タイトル";

int Enemy::EnemyCount = 0;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player(400, 600, 10, 30);

	Enemy* enemy1 = new Enemy(400, 200, 8, 25);
	Enemy* enemy2 = new Enemy(200, 400, 8, 25);

	cout << Enemy::EnemyCount << endl;


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		enemy1->Update();
		enemy2->Update();
		player->Move(keys, preKeys);

		int distX = enemy1->GetPosX() - player->bullet->GetPosX();
		int distY = enemy1->GetPosY() - player->bullet->GetPosY();
		int dist = (distX * distX) + (distY * distY);
		int radius = enemy1->GetRadius() + player->bullet->GetRadius();
		
		int distX2 = enemy2->GetPosX() - player->bullet->GetPosX();
		int distY2 = enemy2->GetPosY() - player->bullet->GetPosY();
		int dist2 = (distX2 * distX2) + (distY2 * distY2);
		int radius2 = enemy2->GetRadius() + player->bullet->GetRadius();

		if (dist <= radius * radius || dist2 <= radius2 * radius2) {
			enemy1->~Enemy();
		}

		if (keys[DIK_R] && !preKeys[DIK_R]) {
			Enemy::EnemyCount = 1;
		}

		if (Enemy::EnemyCount < 0) {
			Enemy::EnemyCount = 0;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();
		enemy1->Draw();
		enemy2->Draw();

		Novice::ScreenPrintf(0, 0, "Enemy1 LIFE%d", enemy1->EnemyCount);
		Novice::ScreenPrintf(0, 20, "Enemy2 LIFE%d", enemy2->EnemyCount);
		Novice::ScreenPrintf(0, 40, "WASD : Player Move");
		Novice::ScreenPrintf(0, 60, "SPACE : Shot"); 
		Novice::ScreenPrintf(0, 80, "R : enemy respawn");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}


	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
