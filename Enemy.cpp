#include "include.h"

Enemy enemy[D_Enemy_MAX];

void EnemyInit()
{
	for (int i = 0; i < D_Enemy_MAX; i++) {
		enemy[i].bColor = BLACK;
		enemy[i].fColor = RED;
		enemy[i].x = rand() % 119;
		enemy[i].y = 29;
		enemy[i].body = 'O';
		enemy[i].isAlive = false;
	}
}

void EnemyUpdate()
{
	 EnemyMove();
	 EnemyClipping();

	 EnemyCreate(rand() % 119, 29);
}

void EnemyDraw()
{
	for (int i = 0; i < D_Enemy_MAX; i++) {
		if (enemy[i].isAlive) {
			DrawChar(enemy[i].x, enemy[i].y, enemy[i].body, enemy[i].fColor, enemy[i].bColor);
		}
	}
}

void EnemyMove()
{
	// 0,0(왼쪽위) ~ 119, 29(오른쪽아래)
	for (int i = 0; i < D_Enemy_MAX; i++) {
		if (enemy[i].isAlive) {
			enemy[i].y++;
			if (enemy[i].y < 0) {
				enemy[i].isAlive = false;
			}
		}
	}
}

void EnemyClipping()
{
	for (int i = 0; i < D_Enemy_MAX; i++) {
		if (enemy[i].y >= 30) {
			enemy[i].isAlive = false;
		}
	}
}

void EnemyCreate(int x, int y)
{
	for (int i = 0; i < D_Enemy_MAX; i++) {
		if (!enemy[i].isAlive) {
			enemy[i].x = x;
			enemy[i].y = y;
			enemy[i].isAlive = true;
			break;
		}
	}
}
