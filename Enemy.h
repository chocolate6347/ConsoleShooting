#pragma once
struct Enemy
{
	bool isAlive;
	int x;
	int y;
	char body;
	WORD fColor;
	WORD bColor;
};

void EnemyInit();
void EnemyUpdate();
void EnemyDraw();

void EnemyMove();
void EnemyClipping();
void EnemyCreate(int x, int y);
void Bullet_Enemy_Collision();

extern Enemy enemy[D_Enemy_MAX];
