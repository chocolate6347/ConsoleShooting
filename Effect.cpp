#include "include.h"
Effect effect[D_EFFECT_MAX];
DWORD indexUpdateTime;

char EffectBody[3][3][3] =
{
	{
		{' ', ' ', ' '},
		{' ', '*', ' '},
		{' ', ' ', ' '}
	},

	{
		{' ', '|', ' '},
		{'-', '*', '-'},
		{' ', '|', ' '}
	},

	{
		{'*', '|', '*'},
		{'-', '*', '-'},
		{'*', '|', '*'}
	}
};

void EffectInit()
{
	for (int i = 0; i < D_EFFECT_MAX; i++) {
		effect[i].isAlive = false;
		effect[i].x = 0;
		effect[i].y = 0;
		effect[i].fColor = YELLOW;
		effect[i].bColor = BLACK;
		effect[i].index = 0;
		effect[i].indexUpdateTime = 0;
	}
}

void EffectUpdate()
{
	for (int i = 0; i < D_EFFECT_MAX; i++) {
		if (effect[i].isAlive && effect[i].indexUpdateTime < GetTickCount()) {
			effect[i].index++;
			effect[i].indexUpdateTime = GetTickCount() + 300;

			if (effect[i].index >= 3) {
				effect[i].isAlive = false;
			}
		}
	}
}

void EffectDraw()
{
	for (int i = 0; i < D_EFFECT_MAX; i++) {
		if (effect[i].isAlive) {
			DrawChar(effect[i].x - 1, effect[i].y - 1,
				EffectBody[effect[i].index][0][0], effect[i].fColor, effect[i].bColor);
			DrawChar(effect[i].x, effect[i].y - 1,
				EffectBody[effect[i].index][0][1], effect[i].fColor, effect[i].bColor);
			DrawChar(effect[i].x + 1, effect[i].y - 1,
				EffectBody[effect[i].index][0][2], effect[i].fColor, effect[i].bColor);

			DrawChar(effect[i].x - 1, effect[i].y,
				EffectBody[effect[i].index][1][0], effect[i].fColor, effect[i].bColor);
			DrawChar(effect[i].x, effect[i].y,
				EffectBody[effect[i].index][1][1], effect[i].fColor, effect[i].bColor);
			DrawChar(effect[i].x + 1, effect[i].y,
				EffectBody[effect[i].index][1][2], effect[i].fColor, effect[i].bColor);

			DrawChar(effect[i].x - 1, effect[i].y + 1,
				EffectBody[effect[i].index][2][0], effect[i].fColor, effect[i].bColor);
			DrawChar(effect[i].x, effect[i].y + 1,
				EffectBody[effect[i].index][2][1], effect[i].fColor, effect[i].bColor);
			DrawChar(effect[i].x + 1, effect[i].y + 1,
				EffectBody[effect[i].index][2][2], effect[i].fColor, effect[i].bColor);
		}
	}
}

void CreateEffect(int x, int y)
{
	for (int i = 0; i < D_EFFECT_MAX; i++) {
		if (!effect[i].isAlive) {
			effect[i].indexUpdateTime = GetTickCount() + 300;
			effect[i].index = 0;
			effect[i].x = x;
			effect[i].y = y;
			effect[i].isAlive = true;
			break;
		}
	}
}
