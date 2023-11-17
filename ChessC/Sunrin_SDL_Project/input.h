#pragma once

// Ű�� ���� ���¸� �����մϴ�.
#define KEY_NONE -1
#define KEY_DOWN 0
#define KEY_PRESS 1
#define KEY_UP 2

// Ű���� ������ ������Ʈ �մϴ�.
void updateKeyState();

// ���ǿ� ���� Ű ������ �����ɴϴ�.
int getKeyState(int keyCode);

// ���콺�� ���� ���·� ������Ʈ �մϴ�.
void updateMouseState();

// ���ǿ� ���� ���콺 ��ư ������ �����ɴϴ�.
int getButtonState(int buttonCode);

// ���� �������� ���콺 ��ġ ������ �����ɴϴ�.
void getCurrentMousePos(int* currentPosX, int* currentPosY);

// ���� �������� ���콺 ��ġ ������ �����ɴϴ�.
void getBeforeMousePos(int* beforePosX, int* beforePosY);

// ���� �����ӿ��� ���콺�� �󸶳� �̵��ߴ����� �����ɴϴ�.
void getDeltaMousePos(int* deltaPosX, int* deltaPosY);