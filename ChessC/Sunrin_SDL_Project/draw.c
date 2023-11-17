#include "draw.h"

void drawFilledRectangle(SDL_Surface* renderer, int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    // ��Ʈ�� �׷���!
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &rect);

}

void drawFilledTriangle(SDL_Surface* renderer, int x1, int y1, int x2, int y2, int x3, int y3, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_Vertex triangleVertex[3] =
    {
        {
            { x1, y1 },             // ù��° ���� ��ġ
            { r, g, b, a },   // ù��° ���� ����
            { 0.f, 0.f }
        },
        {
            { x2, y2 },            // �ι�° ���� ��ġ
            { r, g, b, a },   // �ι�° ���� ����
            { 0.f, 0.f }
        },
        {
            { x3, y3 },            // ����° ���� ��ġ
            { r, g, b, a },   // ����° ���� ����
            { 0.f, 0.f }
        }
    };

    SDL_RenderGeometry(renderer, NULL, triangleVertex, 3, NULL, 0);
}

void drawFilledCircle(SDL_Surface* renderer, int x, int y, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);

    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; 
            int dy = radius - h; 
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                // ������ �ȿ� �ִ� ��� ���� ����ϴ�.
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }

}
