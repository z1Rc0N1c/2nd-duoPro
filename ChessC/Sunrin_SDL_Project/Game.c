#include "pch.h"

GameScene gameScene;

void GameScene_Init()
{
	SDL_Renderer* renderer = Get_Renderer();

	gameScene.order = 1;

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
			if (gameScene.nodeArray[j][i]->object)
				printf("%d", gameScene.nodeArray[j][i]->object->objectType);
			else printf("_");
		}
		printf("\n");
	}

	gameScene.attainableSlots = (List*)malloc(sizeof(List*));
	list_init(gameScene.attainableSlots);

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

	int fixedMouseX = mouseX - gameScene.board.x - 50;
	int fixedMouseY = mouseY - gameScene.board.y - 50;
	if (getButtonState(SDL_BUTTON_LEFT) == KEY_DOWN) {
		if (fixedMouseX >= 0 && fixedMouseX < 800 && fixedMouseY >= 0 && fixedMouseY < 800) {
			Slot* targetSlot = gameScene.nodeArray[fixedMouseX / 100][fixedMouseY / 100];
			if (targetSlot->object) {
				if (targetSlot->object->team == gameScene.order) {
					if (gameScene.selectedArray) {
						gameScene.selectedArray = (gameScene.selectedArray->x == targetSlot->x
							&& gameScene.selectedArray->y == targetSlot->y) ?
							NULL : targetSlot;
						return;
					}
					else {
						gameScene.selectedArray = targetSlot;
						return;
					}
				}
				else if (!gameScene.selectedArray) return;
			}
			//�ٸ� �� �̰ų� �� ����
			if (gameScene.selectedArray) {
				for (int i = 0; i < gameScene.selectedArray->object->moveAllowedSlots->len; i++) {
					Slot* slot = list_search(gameScene.selectedArray->object->moveAllowedSlots, i);
					if (slot->x == targetSlot->x && slot->y == targetSlot->y) {

						gameScene.order = (gameScene.order) ? 0 : 1;
						gameScene.selectedArray->object->isFirstMoved = true;
						if (slot->object) {
							slot->object = gameScene.selectedArray->object;
							gameScene.selectedArray->object = NULL;
							gameScene.selectedArray = NULL;
							slot->object->xPos = slot->x;
							slot->object->yPos = slot->y;
							break;
						}
						else {
							slot->object = gameScene.selectedArray->object;
							gameScene.selectedArray->object = NULL;
							gameScene.selectedArray = NULL;
							slot->object->xPos = slot->x;
							slot->object->yPos = slot->y;
							break;
						}

					}

				}
			}




		}
	}

	printf("%d", gameScene.order);

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

	//ü���� ǥ��
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

	//ü�� �� ǥ��
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Slot* newNode = gameScene.nodeArray[i][j];
			if (newNode->object) {
				drawTextureWithRatio(renderer, newNode->positionX - 50, newNode->positionY - 50, 0.18, 0.18,
					gameScene.objectImages[newNode->object->team][newNode->object->objectType]);
			}
		}
	}

	//���õ� ������Ʈ ǥ��
	if (gameScene.selectedArray && gameScene.selectedArray->object) {
		move_obj(&gameScene, gameScene.selectedArray->object);
		drawFilledCircle(renderer, gameScene.selectedArray->positionX, gameScene.selectedArray->positionY, 30, 200, 200, 200, 150);


		//�̵� ������ ������Ʈ ǥ��
		if (gameScene.selectedArray && gameScene.selectedArray->object) {
			Node* currentNode = gameScene.selectedArray->object->moveAllowedSlots->head;
			while (currentNode) {
				Slot* value = currentNode->val;
				drawFilledCircle(renderer, value->positionX, value->positionY, 15, 200, 200, 200, 150);
				currentNode = currentNode->next;
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
