#pragma once
typedef struct GameScene {
	// 씬에서 전역적으로 사용할 변수는 구조체로 랩핑해서 사용합니다.
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
// 씬별 초기화 함수를 정의합니다.
// 여기서는 사용할 자료를 초기화 합니다.
void GameScene_Init();

// Event 함수를 정의합니다.
void GameScene_Event();

// Update 함수를 정의합니다.
void GameScene_Update();

// Render 함수를 정의합니다.
void GameScene_Render();

// Release 함수를 정의합니다.
void GameScene_Release();

// 메인 화면에서 시작할 게임 루프를 정의합니다.
int GameScene_Loop();