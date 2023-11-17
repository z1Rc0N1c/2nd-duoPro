#include "pch.h"
#include "font.h"
#include <SDL.h>

void drawText(SDL_Renderer* renderer, TTF_Font* font, const char* str, int x, int y, SDL_Color c)
{
    // ��Ʈ�� ������ �ؼ� Surface�� �׸��ϴ�.
    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, str, c);

    // SDL_Texture�� ��ȯ�Ͽ�, renderer�� �׸� �� �ֵ��� �غ��մϴ�.
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    // �ؽ�Ʈ�� ��ġ�� �����մϴ�.
    SDL_Rect r = { x, y, surface->w, surface->h };

    // �� �̻� ������� �ʴ� surface�� �����մϴ�.
    SDL_FreeSurface(surface);

    // renderer�� texture�� ������ �����մϴ�.
    SDL_RenderCopy(renderer, texture, NULL, &r);

    // ������ ������ texture�� ������ ���̻� �ʿ����� �ʽ��ϴ�.
    // ����!
    SDL_DestroyTexture(texture);
}

void drawTextCenter(SDL_Renderer* renderer, TTF_Font* font, const char* str, int x, int y, SDL_Color c)
{
    // ��Ʈ�� ������ �ؼ� Surface�� �׸��ϴ�.
    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, str, c);

    // SDL_Texture�� ��ȯ�Ͽ�, renderer�� �׸� �� �ֵ��� �غ��մϴ�.
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    // �ؽ�Ʈ�� ��ġ�� �����մϴ�.
    SDL_Rect r = { x - surface->w/2, y - surface->h/2, surface->w, surface->h };

    // �� �̻� ������� �ʴ� surface�� �����մϴ�.
    SDL_FreeSurface(surface);

    // renderer�� texture�� ������ �����մϴ�.
    SDL_RenderCopy(renderer, texture, NULL, &r);

    // ������ ������ texture�� ������ ���̻� �ʿ����� �ʽ��ϴ�.
    // ����!
    SDL_DestroyTexture(texture);
}

void drawTextCenterWRatio(SDL_Renderer* renderer, TTF_Font* font, const char* str, int x, int y, SDL_Color c, double ratio_x, double ratio_y)
{
    // ��Ʈ�� ������ �ؼ� Surface�� �׸��ϴ�.
    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, str, c);

    // SDL_Texture�� ��ȯ�Ͽ�, renderer�� �׸� �� �ֵ��� �غ��մϴ�.
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    int w = surface->w * ratio_x;
    int h = surface->h * ratio_y;

    // �ؽ�Ʈ�� ��ġ�� �����մϴ�.
    SDL_Rect r = { x - w / 2, y - h / 2, w, h };

    // �� �̻� ������� �ʴ� surface�� �����մϴ�.
    SDL_FreeSurface(surface);

    // renderer�� texture�� ������ �����մϴ�.
    SDL_RenderCopy(renderer, texture, NULL, &r);

    // ������ ������ texture�� ������ ���̻� �ʿ����� �ʽ��ϴ�.
    // ����!
    SDL_DestroyTexture(texture);
}
