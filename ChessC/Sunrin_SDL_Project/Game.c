#include "pch.h"
#include "Game.h" // include!

 //필요한 변수는 전역 변수로 전언해서 사용합니다.
typedef struct Slot {
	int x, y;
	int positionX;
	int positionY;
	Object* object;
} Slot;

typedef struct GameScene {
	// 씬에서 전역적으로 사용할 변수는 구조체로 랩핑해서 사용합니다.

	SDL_Rect board;
	Slot* nodeArray[8][8];

	SDL_Color mapColor[2];

	int quit;
} GameScene;
GameScene gameScene;




void GameScene_Init()
{
	SDL_Renderer* renderer = Get_Renderer();

	gameScene.board.w = 800;
	gameScene.board.h = 800;
	gameScene.board.x = SCREEN_WIDTH / 2 - (gameScene.board.w / 2);
	gameScene.board.y = SCREEN_HEIGHT / 2 - (gameScene.board.h / 2);


	//슬롯 초기호화
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Slot* newNode = (Slot*)malloc(sizeof(Node));
			newNode->x = i;
			newNode->y = j;
			newNode->object = NULL;
			newNode->positionX = gameScene.board.x + (gameScene.board.w / 8) * (i + 1);
			newNode->positionY = gameScene.board.y + (gameScene.board.h / 8) * (j + 1);
			gameScene.nodeArray[i][j] = newNode;
		}
	}
	SDL_Color tempColor1 = { 102, 153, 102, 255 };
	SDL_Color tempColor2 = { 255, 255, 204, 255 };

	gameScene.mapColor[0] = tempColor1;
	gameScene.mapColor[1] = tempColor2;


	//말 초기화
	for (int i = 0; i < 8; i++) {

	}

}

void GameScene_Event()
{
	// SDL 이벤트를 확인하기 위한 객체 생성
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		// event의 타입이 SDL_QUIT면 트리거를 활성화 합니다.
		if (event.type == SDL_QUIT) {
			gameScene.quit = EXIT_GAME;
			break;
		}
	}
}

void GameScene_Update()
{
	double dt = getDeltaTime();

}

void GameScene_Render()
{
	SDL_Renderer* renderer = Get_Renderer();

	// 회색 배경을 칠합니다.
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 50);
	SDL_RenderClear(renderer);


	int colorSwitch = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Slot* newNode = gameScene.nodeArray[i][j];

			drawFilledRectangle(renderer, newNode->positionX - 50
				, newNode->positionY - 50, 100, 100,
				gameScene.mapColor[colorSwitch].r, gameScene.mapColor[colorSwitch].g,
				gameScene.mapColor[colorSwitch].b, gameScene.mapColor[colorSwitch].a);
			colorSwitch = !colorSwitch;
		}
		colorSwitch = !colorSwitch;
	}


	//drawTexture(renderer, 0, 0, loadTexture(renderer, "D:\Coding\VisualStudio\ZOMVILLE\Sunrin_SDL_Project\resources"));

	// 오브젝트를 그리는 코드를 작성합니다.

	SDL_RenderPresent(renderer);
}

void GameScene_Release()
{
	// 사용한 자료를 해제합니다.

}

int GameScene_Loop()
{
	// 필요한 변수를 초기화 합니다.
	// 꼭, 씬에서 계속 사용할 변수는 이곳에서 초기화 합니다.
	gameScene.quit = SCENE_LOOP;

	// 루프를 진행합니다.
	while (gameScene.quit == SCENE_LOOP) {
		// 유틸 함수를 업데이트 합니다.
		// 이를 씬별로 수행해야, 여러 함수들을 정상적으로 사용할 수 있습니다.
		Update_Util();

		GameScene_Event();
		GameScene_Update();
		GameScene_Render();
	}

	// 씬의 정보를 확인해서 내보냅니다.
	return gameScene.quit;
}
