#pragma once
struct Bullet
{
	bool isAlive; 
	int x;
	int y;
	char body;
	WORD fColor;
	WORD bColor;
};

void BulletInit();
void BulletUpdate();
void BulletDraw();

void BulletMove();
void BulletClipping();
void BulletCreate(int x, int y);

extern Bullet bullet[D_BULLET_MAX];
