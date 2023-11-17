#pragma once
#include <SDL_image.h>

// SDL_image ���̺귯���� �ʱ�ȭ �մϴ�.
int initImage();

// �̹����� �ҷ��ɴϴ�.
// renderer: �̹����� ����� Ÿ�� ������
// file: �ҷ��� ���� ���
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* file);

// �̹����� ����մϴ�.
// renderer: �̹����� ����� Ÿ�� ������
// x: �׸� �̹����� x ��ġ
// y: �׸� �̹����� y ��ġ
// texture: �׸� �̹����� ����
void drawTexture(SDL_Renderer* renderer, int x, int y, SDL_Texture* texture);

// �̹����� ����մϴ�.
// renderer: �̹����� ����� Ÿ�� ������
// x: �׸� �̹����� x ��ġ
// y: �׸� �̹����� y ��ġ
// widthRatio: ���� �ؽ�ó���� �������� �׸� ���� �����Դϴ�.
// heightRatio: ���� �ؽ�ó���� �������� �׸� ���� �����Դϴ�.
// texture: �׸� �̹����� ����
// example: widthRatio, heightRatio�� 0.5�̸� ���� �ؽ����� 0.5�� ũ�⸸ŭ �������� �����մϴ�.
void drawTextureWithRatio(SDL_Renderer* renderer, int x, int y, double widthRatio, double heightRatio, SDL_Texture* texture);

// �̹����� ����մϴ�.
// renderer: �̹����� ����� Ÿ�� ������
// rect: �̹����� ����� ��ġ�� �̹����� ũ��
// texture: �׸� �̹����� ����
void drawTextureWithRect(SDL_Renderer* renderer, SDL_Rect* rect, SDL_Texture* texture);

// Ÿ�� �̹����� width, height ������ �����ɴϴ�.
// ������ SDL_QueryTexture �ڵ带 ������ �����Դϴ�.
void getTextureSize(SDL_Texture* texture, int* x, int* y);