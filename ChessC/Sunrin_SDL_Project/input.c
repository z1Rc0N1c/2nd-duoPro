#include "pch.h"
#include "SDL.h"
#include "input.h"

// Ű���� ������ �ʿ��� �������� �����մϴ�.
// SDL_NUM_SCANCODES: ��ĵ �ڵ��� ���� ��ȯ�մϴ�. (512)
size_t memSize = sizeof(Uint8) * SDL_NUM_SCANCODES; // �迭�� Ű�⸦ �����մϴ�.
const Uint8* currentKeyState = NULL;                // ���� Ű ������ ������ �����͸� �����մϴ�. (API�� �����ɴϴ�.)
// ���� �Ҵ翡 ���� ������ �����ϱ� ���� ���� �迭�� �����մϴ�.
const Uint8 beforeKeyState[SDL_NUM_SCANCODES];      // ���� Ű ������ ������ �迭�� �����մϴ�.

// ���콺 ������ ���õ� �������� �����մϴ�.
int beforeMousePosX = 0;
int beforeMousePosY = 0;
int currentMousePosX = 0;
int currentMousePosY = 0;
Uint32 beforeMouseState = 0;
Uint32 currentMouseState = 0;

// �Լ� ���Ǹ� �����մϴ�! ------------

void updateKeyState()
{
    // Ű ���¸� �ʱ�ȭ �մϴ�.
    if (currentKeyState == NULL) {
        currentKeyState = SDL_GetKeyboardState(NULL);
    }

    SDL_memcpy(beforeKeyState, currentKeyState, memSize);
}

int getKeyState(int keyCode)
{
    if (beforeKeyState[keyCode] == 0 && currentKeyState[keyCode] == 0)
        return KEY_NONE;
    if (beforeKeyState[keyCode] == 0 && currentKeyState[keyCode] == 1)
        return KEY_DOWN;
    if (beforeKeyState[keyCode] == 1 && currentKeyState[keyCode] == 1)
        return KEY_PRESS;
    if (beforeKeyState[keyCode] == 1 && currentKeyState[keyCode] == 0)
        return KEY_UP;
}

void updateMouseState() {
    beforeMousePosX = currentMousePosX;
    beforeMousePosY = currentMousePosY;

    beforeMouseState = currentMouseState;
    currentMouseState = SDL_GetMouseState(&currentMousePosX, &currentMousePosY);
}

int getButtonState(int buttonCode) {
    Uint32 buttonMask = SDL_BUTTON(buttonCode);
    int before = beforeMouseState & buttonMask;
    int current = currentMouseState & buttonMask;

    if (before == 0 && current == 0)
        return KEY_NONE;
    if (before == 0 && current == 1)
        return KEY_DOWN;
    if (before == 1 && current == 1)
        return KEY_PRESS;
    if (before == 1 && current == 0)
        return KEY_UP;
}

void getCurrentMousePos(int* currentPosX, int* currentPosY) {
    // *�����ڷ� �����Ϳ� �����ؼ� ���� �����մϴ�.
    if (currentPosX != NULL) {
        *currentPosX = currentMousePosX;
    }
    if (currentPosY != NULL) {
        *currentPosY = currentMousePosY;
    }
}

void getBeforeMousePos(int* beforePosX, int* beforePosY) {
    // *�����ڷ� �����Ϳ� �����ؼ� ���� �����մϴ�.
    if (beforePosX != NULL) {
        *beforePosX = beforeMousePosX;
    }
    if (beforePosY != NULL) {
        *beforePosY = beforeMousePosY;
    }
}

void getDeltaMousePos(int* deltaPosX, int* deltaPosY) {
    // *�����ڷ� �����Ϳ� �����ؼ� ���� �����մϴ�.
    if (deltaPosX != NULL) {
        *deltaPosX = currentMousePosX - beforeMousePosX;
    }
    if (deltaPosY != NULL) {
        *deltaPosY = currentMousePosY - beforeMousePosY;
    }
}
