#include "pch.h"
#include "Start.h" // include!

// �ʿ��� ������ ���� ������ �����ؼ� ����մϴ�.
typedef struct Scene {
	// ������ ���������� ����� ������ ����ü�� �����ؼ� ����մϴ�.
	SDL_Texture* img_map;

	SDL_Rect rect_startButton;
	SDL_Rect rect_exitButton;

	TTF_Font* font;


	int quit;
} Scene;

Scene scene;

void Start_Init()
{
	SDL_Renderer* renderer = Get_Renderer();

	//scene.img_background = loadTexture(renderer, "");
	scene.img_map = loadTexture(renderer, "./resources/StartImage.jpg");


	getTextureSize(scene.img_map,
		&scene.rect_startButton.w, &scene.rect_startButton.h);

	scene.rect_startButton.w = 200;
	scene.rect_startButton.h = 80;
	scene.rect_startButton.x = SCREEN_WIDTH/2 - scene.rect_startButton.w / 2;
	scene.rect_startButton.y = SCREEN_HEIGHT/2 + 150 - scene.rect_startButton.h /2;


	scene.font = TTF_OpenFont("./resources/Pretendard.otf", 80);

}

void Start_Event()
{
	// SDL �̺�Ʈ�� Ȯ���ϱ� ���� ��ü ����
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		// event�� Ÿ���� SDL_QUIT�� Ʈ���Ÿ� Ȱ��ȭ �մϴ�.
		if (event.type == SDL_QUIT) {
			scene.quit = EXIT_GAME;
			break;
		}
	}
}

void Start_Update()
{
	double dt = getDeltaTime();

	// ���콺 ��ġ�� �����ɴϴ�.
	int mouseX, mouseY = 0;
	getCurrentMousePos(&mouseX, &mouseY);


	if (getButtonState(SDL_BUTTON_LEFT) == KEY_DOWN) {
		// startButton�� ���ȴ��� üũ�Ѵ�.
		if (checkCollisionWithPoint(scene.rect_startButton, mouseX, mouseY)) {
			printf("GameScene���� �̵��մϴ�. \n");
			scene.quit = GAME_SCENE;
		}
	}
	
}

void Start_Render()
{
	SDL_Renderer* renderer = Get_Renderer();

	// ȸ�� ����� ĥ�մϴ�.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	
	drawTextureWithRatio(renderer, 0,0, 2, 2, scene.img_map);
	drawFilledRectangle(renderer, scene.rect_startButton.x
		, scene.rect_startButton.y
		, scene.rect_startButton.w, scene.rect_startButton.h, 255, 255, 255, 255);
	
	// ������Ʈ�� �׸��� �ڵ带 �ۼ��մϴ�.

	SDL_Color textureColor1 = { 255, 255, 255, 255 };
	drawTextCenter(renderer, scene.font, u8"Chess", SCREEN_WIDTH / 2, 200, textureColor1);

	SDL_Color textureColor2 = { 0, 0, 0, 255 };
	drawTextCenter(renderer, scene.font, u8"Start", scene.rect_startButton.x + scene.rect_startButton.w / 2,
		scene.rect_startButton.y + scene.rect_startButton.h / 2, textureColor2);


	SDL_RenderPresent(renderer);


}

void Start_Release()
{
	SDL_DestroyTexture(scene.img_map);

}

int Start_Loop()
{
	// �ʿ��� ������ �ʱ�ȭ �մϴ�.
	// ��, ������ ��� ����� ������ �̰����� �ʱ�ȭ �մϴ�.
	scene.quit = SCENE_LOOP;

	// ������ �����մϴ�.
	while (scene.quit == SCENE_LOOP) {
		// ��ƿ �Լ��� ������Ʈ �մϴ�.
		// �̸� ������ �����ؾ�, ���� �Լ����� ���������� ����� �� �ֽ��ϴ�.
		Update_Util();

		Start_Event();
		Start_Update();
		Start_Render();
	}

	// ���� ������ Ȯ���ؼ� �������ϴ�.
	return scene.quit;
}
