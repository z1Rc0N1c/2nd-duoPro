#pragma once
typedef struct GameScene {
	// ������ ���������� ����� ������ ����ü�� �����ؼ� ����մϴ�.
	short order;
	SDL_Rect board;
	struct Slot* nodeArray[8][8];


	SDL_Color mapColor[2];
	SDL_Texture* objectImages[2][6];
	SDL_Texture* selectIcon;

	int quit;
	struct Slot* selectedArray;

	struct Object* wKing;
	struct Object* bKing;

} GameScene;

typedef struct Slot {
	int x, y;
	int positionX;
	int positionY;
	struct Object* object;
} Slot;
// ���� �ʱ�ȭ �Լ��� �����մϴ�.
// ���⼭�� ����� �ڷḦ �ʱ�ȭ �մϴ�.
void GameScene_Init();

// Event �Լ��� �����մϴ�.
void GameScene_Event();

// Update �Լ��� �����մϴ�.
void GameScene_Update();

// Render �Լ��� �����մϴ�.
void GameScene_Render();

// Release �Լ��� �����մϴ�.
void GameScene_Release();

// ���� ȭ�鿡�� ������ ���� ������ �����մϴ�.
int GameScene_Loop();