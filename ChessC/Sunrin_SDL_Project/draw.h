#pragma once
#include <SDL.h>

// drawFilledRectangle: �簢���� �׸��ϴ�.
// x, y: �׸� ��ǥ
// w, h: �׸� ũ��
// r, g, b: �׸� ����
void drawFilledRectangle(SDL_Surface* renderer,
	int x, int y, int w, int h,
	Uint8 r, Uint8 g, Uint8 b, Uint8 a);

// �ﰢ�� �׸��� �Լ�
void drawFilledTriangle(SDL_Surface* renderer,
	int x1, int y1,		// ù ��° ���� ��ǥ
	int x2, int y2,		// �� ��° ���� ��ǥ
	int x3, int y3,		// �� ��° ���� ��ǥ
	Uint8 r, Uint8 g, Uint8 b, Uint8 a);

// �� �׸��� �Լ�
void drawFilledCircle(SDL_Surface* renderer,
	int x, int y,
	int radius,
	Uint8 r, Uint8 g, Uint8 b, Uint8 a);