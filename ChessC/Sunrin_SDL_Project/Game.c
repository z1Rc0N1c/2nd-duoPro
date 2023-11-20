#include "pch.h"

GameScene gameScene;

void GameScene_Init()
{
	SDL_Renderer* renderer = Get_Renderer();

	gameScene.board.w = 800;
	gameScene.board.h = 800;
	gameScene.board.x = SCREEN_WIDTH / 2 - (gameScene.board.w / 2);
	gameScene.board.y = SCREEN_HEIGHT / 2 - (gameScene.board.h / 2);

	gameScene.objectImages[0][0] = loadTexture(renderer, "./resources/Bpawn.png");
	gameScene.objectImages[0][1] = loadTexture(renderer, "./resources/Brook.png");
	gameScene.objectImages[0][2] = loadTexture(renderer, "./resources/Bknight.png");
	gameScene.objectImages[0][3] = loadTexture(renderer, "./resources/Bbishop.png");
	gameScene.objectImages[0][4] = loadTexture(renderer, "./resources/Bqueen.png");
	gameScene.objectImages[0][5] = loadTexture(renderer, "./resources/Bking.png");
	gameScene.objectImages[1][0] = loadTexture(renderer, "./resources/Wpawn.png");
	gameScene.objectImages[1][1] = loadTexture(renderer, "./resources/Wrook.png");
	gameScene.objectImages[1][2] = loadTexture(renderer, "./resources/Wknight.png");
	gameScene.objectImages[1][3] = loadTexture(renderer, "./resources/Wbishop.png");
	gameScene.objectImages[1][4] = loadTexture(renderer, "./resources/Wqueen.png");
	gameScene.objectImages[1][5] = loadTexture(renderer, "./resources/Wking.png");
	gameScene.selectIcon = loadTexture(renderer, "./resources/SelectIcon.png");

	SDL_Color tempColor1 = { 102, 153, 102, 255 };
	SDL_Color tempColor2 = { 255, 255, 204, 255 };

	gameScene.mapColor[0] = tempColor1;
	gameScene.mapColor[1] = tempColor2;

	assignMent(&gameScene);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (gameScene.nodeArray[i][j]->object)
				printf("%d", gameScene.nodeArray[i][j]->object->objectType);
			else printf("_");
		}
		printf("\n");
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

	// 마우스 위치를 가져옵니다.
	int mouseX, mouseY = 0;
	getCurrentMousePos(&mouseX, &mouseY);

	int fixedMouseX = mouseX - gameScene.board.x - 50;
	int fixedMouseY = mouseY - gameScene.board.y - 50;
	if (getButtonState(SDL_BUTTON_LEFT) == KEY_DOWN) {
		if (fixedMouseX >= 0 && fixedMouseX < 800 && fixedMouseY >= 0 && fixedMouseY < 800) {
			Slot* targetSlot = gameScene.nodeArray[fixedMouseX / 100][fixedMouseY / 100];
			if (targetSlot) {
				if (gameScene.selectedArray)
					gameScene.selectedArray = (gameScene.selectedArray->x == targetSlot->x
						&& gameScene.selectedArray->y == targetSlot->y) ?
					NULL : targetSlot;
				else gameScene.selectedArray = targetSlot;
			}



		}
	}

	printf("%d", (gameScene.selectedArray) ? 1 : 0);

	//if (getButtonState(SDL_BUTTON_LEFT) == KEY_DOWN) {
	//	// startButton이 눌렸는지 체크한다.
	//	if (checkCollisionWithPoint(scene.rect_startButton, mouseX, mouseY)) {
	//		printf("GameScene으로 이동합니다. \n");
	//		scene.quit = GAME_SCENE;
	//	}
	//}

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
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Slot* newNode = gameScene.nodeArray[i][j];
			if (newNode->object) {
				drawTextureWithRatio(renderer, newNode->positionX - 50, newNode->positionY - 50, 0.18, 0.18,
					gameScene.objectImages[newNode->object->team][newNode->object->objectType]);
			}
		}
	}

	if (gameScene.selectedArray) {
		//drawTextureWithRatio(renderer, gameScene.selectedArray->positionX - 50, gameScene.selectedArray->positionY - 50, 0.4, 0.4,
		//	gameScene.selectIcon);
		drawFilledCircle(renderer, gameScene.selectedArray->positionX, gameScene.selectedArray->positionY, 30, 200, 200, 200, 150);

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
