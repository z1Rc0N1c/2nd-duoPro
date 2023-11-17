#include "pch.h"
#include "image.h"

int initImage()
{
	// IMG_INIT�� �ʱ�ȭ �ϱ� ���� �÷��� �Դϴ�.
	// �ҷ��� �̹��� ������ ���� �����Դϴ�.
	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;

	// IMG_INIT�� �ʱ�ȭ�� �÷��׿� ���� ������ �����մϴ�.
	// ���� & �����ڷ� ���������� �ʱ�ȭ �Ǿ����� �ľ��մϴ�.
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image�� �ʱ�ȭ ���� ���߽��ϴ�! \nSDL_image Error: %s\n", IMG_GetError());
		return -1;
	}

    return 0;
}

SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* file)
{
	SDL_Surface* surface;
	SDL_Texture* texture;

	// ������ �о� SDL_Surface�� �����մϴ�.
	surface = IMG_Load(file);
	if (surface == NULL) {
		printf("������ ���� �� �����ϴ�: %s\n", file);
		return NULL;
	}

	// SDL_CreateTextureFromSurface�� ���� SDL_Texture�� �����մϴ�.
	// �־��� Surface�� ���ο� Texture�� �����մϴ�.
	// ȭ�鿡 �׸� renderer�� �ʿ��մϴ�.
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL) {
		printf("texture�� ������ �� �����ϴ�.\n");
	}

	// ���� Texture�� ���������, ���ʿ��� surface�� �����մϴ�.
	SDL_FreeSurface(surface);

	return texture;
}

void drawTexture(SDL_Renderer* renderer, int x, int y, SDL_Texture* texture)
{
	SDL_Rect src;
	SDL_Rect dst;

	src.x = 0;
	src.y = 0;
	// �ؽ����� �Ӽ�(format, width, height ��)�� �����ɴϴ�.
	SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);

	// �������� �׸� �ؽ����� ��ġ ������ �����մϴ�.
	dst.x = x;
	dst.y = y;
	dst.w = src.w;
	dst.h = src.h;

	// dst�� ������ ��ġ ������ texture�� �׸��ϴ�.
	SDL_RenderCopy(renderer, texture, NULL, &dst);
}

void drawTextureWithRatio(SDL_Renderer* renderer, int x, int y, double widthRatio, double heightRatio, SDL_Texture* texture)
{
	SDL_Rect src;
	SDL_Rect dst;

	src.x = 0;
	src.y = 0;
	// �ؽ����� �Ӽ�(format, width, height ��)�� �����ɴϴ�.
	SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);

	// �������� �׸� �ؽ����� ��ġ ������ �����մϴ�.
	// �׸� ������ ���� ũ�⸦ �����մϴ�.
	dst.x = x;
	dst.y = y;
	dst.w = (int)(src.w * widthRatio);
	dst.h = (int)(src.h * heightRatio);

	// dst�� ������ ��ġ ������ texture�� �׸��ϴ�.
	SDL_RenderCopy(renderer, texture, NULL, &dst);
}

void drawTextureWithRect(SDL_Renderer* renderer, SDL_Rect* rect, SDL_Texture* texture)
{
	// dst�� ������ ��ġ ������ texture�� �׸��ϴ�.
	SDL_RenderCopy(renderer, texture, NULL, rect);
}

void getTextureSize(SDL_Texture* texture, int* x, int* y)
{
	SDL_QueryTexture(texture, NULL, NULL, x, y);
}
