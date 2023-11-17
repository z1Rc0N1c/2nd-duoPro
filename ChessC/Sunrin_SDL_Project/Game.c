#include "pch.h"
#include "Game.h" // include!

 //�ʿ��� ������ ���� ������ �����ؼ� ����մϴ�.
typedef struct Slot {
	int x, y;
	int positionX;
	int positionY;
	Object* object;
} Slot;

typedef struct GameScene {
	// ������ ���������� ����� ������ ����ü�� �����ؼ� ����մϴ�.

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


	//���� �ʱ�ȣȭ
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


	//�� �ʱ�ȭ
	for (int i = 0; i < 8; i++) {

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
