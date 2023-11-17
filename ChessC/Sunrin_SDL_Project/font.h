#pragma once
#include <SDL_ttf.h>

// drawText
// renderer: �׸� ������
// font: �׸� ��Ʈ
// str: �׸� �ؽ�Ʈ
void drawText(SDL_Renderer* renderer, TTF_Font* font, const char* str, int x, int y, SDL_Color c);

void drawTextCenter(SDL_Renderer* renderer, TTF_Font* font, const char* str, int x, int y, SDL_Color c);

// �ؽ�Ʈ�� ũ�⸦ ������ �� �ֽ��ϴ�.
// ratio_x, ratio_y ��� 1.0 �̸�, ���� �Դϴ�.
// ratio_x, ratio_y ��� 0.5 �̸�, ���� ũ��� ��µ˴ϴ�.
void drawTextCenterWRatio(SDL_Renderer* renderer, TTF_Font* font, const char* str, int x, int y, SDL_Color c, double ratio_x, double ratio_y);