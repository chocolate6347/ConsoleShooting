#include "include.h"

Enemy enemy[D_Enemy_MAX];
DWORD createEnemyTime;

void EnemyInit()
{
	for (int i = 0; i < D_Enemy_MAX; i++) {
		enemy[i].bColor = BLACK;
		enemy[i].fColor = RED;
		enemy[i].x = rand() % 119;
		enemy[i].y = 0;
		enemy[i].body = 'O';
		enemy[i].isAlive = false;
	}
}

void EnemyUpdate()
{
	if (GetTickCount() > createEnemyTime) {
		createEnemyTime = GetTickCount() + 500;

		EnemyCreate(rand() % 120, -1);
	}

	 EnemyMove();
	 EnemyClipping();
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

void Bullet_Enemy_Collision()
{
	for (int i = 0; i < D_BULLET_MAX; i++) {
		if (bullet[i].isAlive) {
			for (int j = 0; j < D_Enemy_MAX; j++) {
				if (enemy[j].isAlive &&
					bullet[i].x == enemy[j].x &&
					(bullet[i].y == enemy[j].y || bullet[i].y - 1 == enemy[j].y))
				{
					bullet[i].isAlive = false;
					enemy[j].isAlive = false;
					CreateEffect(enemy[j].x, enemy[j].y);
					break;
				}
			}
		}
	}
}
