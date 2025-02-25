#pragma once
struct Effect
{
	bool isAlive;
	int x;
	int y;
	WORD fColor;
	WORD bColor;

	int index;
	DWORD indexUpdateTime;
};

void EffectInit();
void EffectUpdate();
void EffectDraw();

void CreateEffect(int x, int y);

extern Effect effect[D_EFFECT_MAX];
