#include "pch.h"

 //�ʿ��� ������ ���� ������ �����ؼ� ����մϴ�.



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


	////���� �ʱ�ȣȭ
	//for (int i = 0; i < 8; i++) {
	//	for (int j = 0; j < 8; j++) {
	//		Slot* newNode = (Slot*)malloc(sizeof(Node));
	//		newNode->x = i;
	//		newNode->y = j;
	//		newNode->object = NULL;
	//		newNode->positionX = gameScene.board.x + (gameScene.board.w / 8) * (i + 1);
	//		newNode->positionY = gameScene.board.y + (gameScene.board.h / 8) * (j + 1);
	//		gameScene.nodeArray[i][j] = newNode;
	//	}
	//}
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
	// SDL �̺�Ʈ�� Ȯ���ϱ� ���� ��ü ����
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		// event�� Ÿ���� SDL_QUIT�� Ʈ���Ÿ� Ȱ��ȭ �մϴ�.
		if (event.type == SDL_QUIT) {
			gameScene.quit = EXIT_GAME;
			break;
		}
	}
}

void GameScene_Update()
{
	double dt = getDeltaTime();

	// ���콺 ��ġ�� �����ɴϴ�.
	int mouseX, mouseY = 0;
	getCurrentMousePos(&mouseX, &mouseY);

	int fixedMouseX = mouseX - gameScene.board.x;
	int fixedMouseY = mouseY - gameScene.board.y;


	//if (getButtonState(SDL_BUTTON_LEFT) == KEY_DOWN) {
	//	// startButton�� ���ȴ��� üũ�Ѵ�.
	//	if (checkCollisionWithPoint(scene.rect_startButton, mouseX, mouseY)) {
	//		printf("GameScene���� �̵��մϴ�. \n");
	//		scene.quit = GAME_SCENE;
	//	}
	//}

}

void GameScene_Render()
{
	SDL_Renderer* renderer = Get_Renderer();

	// ȸ�� ����� ĥ�մϴ�.
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



	//drawTexture(renderer, 0, 0, loadTexture(renderer, "D:\Coding\VisualStudio\ZOMVILLE\Sunrin_SDL_Project\resources"));

	// ������Ʈ�� �׸��� �ڵ带 �ۼ��մϴ�.

	SDL_RenderPresent(renderer);
}

void GameScene_Release()
{
	// ����� �ڷḦ �����մϴ�.

}

int GameScene_Loop()
{
	// �ʿ��� ������ �ʱ�ȭ �մϴ�.
	// ��, ������ ��� ����� ������ �̰����� �ʱ�ȭ �մϴ�.
	gameScene.quit = SCENE_LOOP;

	// ������ �����մϴ�.
	while (gameScene.quit == SCENE_LOOP) {
		// ��ƿ �Լ��� ������Ʈ �մϴ�.
		// �̸� ������ �����ؾ�, ���� �Լ����� ���������� ����� �� �ֽ��ϴ�.
		Update_Util();

		GameScene_Event();
		GameScene_Update();
		GameScene_Render();
	}

	// ���� ������ Ȯ���ؼ� �������ϴ�.
	return gameScene.quit;
}
