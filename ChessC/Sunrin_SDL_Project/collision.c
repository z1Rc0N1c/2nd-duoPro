#include "collision.h"

int checkCollision(SDL_Rect rect1, SDL_Rect rect2)
{
    // �� ���� �簢���� �浹�ϴ��� ���θ� Ȯ��
    if (rect1.x + rect1.w >= rect2.x &&       // rect1 ���� ��谡 rect2 ���� ��踦 ���� �ʰ�
        rect1.x <= rect2.x + rect2.w &&       // rect1 ���� ��谡 rect2 ���� ��踦 ���� ������
        rect1.y + rect1.h >= rect2.y &&       // rect1 �ϴ� ��谡 rect2 ��� ��踦 ���� �ʰ�
        rect1.y <= rect2.y + rect2.h) {       // rect1 ��� ��谡 rect2 �ϴ� ��踦 ���� ������ �浹
        return 1;
    }

    return 0;  // �浹���� ����
}

int checkCollisionWithPoint(SDL_Rect rect, int x, int y)
{
    // �־��� ��ġ (x, y)�� �簢�� ���� �ִ��� Ȯ��
    if (x >= rect.x && x <= rect.x + rect.w &&   // x ��ǥ�� �簢�� ���� ���� �ְ�
        y >= rect.y && y <= rect.y + rect.h) {  // y ��ǥ�� �簢�� ���� ���� ������ �浹
        return 1;
    }

    return 0;  // �浹���� ����
}
