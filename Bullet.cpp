#include "include.h"

Bullet bullet[D_BULLET_MAX];

void BulletInit()
{
	for (int i = 0; i < D_BULLET_MAX; i++) {
		bullet[i].bColor = BLACK;
		bullet[i].fColor = WHITE;
		bullet[i].x = player.x;
		bullet[i].y = player.y - 1;
		bullet[i].body = 'I';
		bullet[i].isAlive = false;
	}
}

void BulletUpdate()
{
	BulletMove();
	BulletClipping();
}

void BulletDraw()
{
	for (int i = 0; i < D_BULLET_MAX; i++) {
		if (bullet[i].isAlive) {
			DrawChar(bullet[i].x, bullet[i].y, bullet[i].body, bullet[i].fColor, bullet[i].bColor);
		}
	}
}

void BulletMove()
{
	// 0,0(왼쪽위) ~ 119, 29(오른쪽아래)
	for (int i = 0; i < D_BULLET_MAX; i++) {
		if (bullet[i].isAlive) {
			bullet[i].y--;
			if (bullet[i].y == -1) {
				bullet[i].isAlive = false;
			}
		}
	}
}

void BulletClipping() {
	for (int i = 0; i < D_BULLET_MAX; i++) {
		if (bullet[i].y < 0) {
			bullet[i].y = 0;
		}
	}
}

void BulletCreate(int x, int y) {

	for (int i = 0; i < D_BULLET_MAX; i++) {

		if (!bullet[i].isAlive && GetAsyncKeyState(VK_SPACE)) {
			bullet[i].x = x;
			bullet[i].y = y - 1;
			bullet[i].isAlive = true;  // 총알 발사
			break;
		}
	}
}
void Bullet_Location() {
	for (int i = 0; i < D_BULLET_MAX; i++) {
		int Bullet_X = bullet[i].x;
		int Bullet_Y = bullet[i].y;
	}
}
