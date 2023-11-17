#include "pch.h"
#include "Start.h" // include!

// 필요한 변수는 전역 변수로 전언해서 사용합니다.
typedef struct Scene {
	// 씬에서 전역적으로 사용할 변수는 구조체로 랩핑해서 사용합니다.
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
	// SDL 이벤트를 확인하기 위한 객체 생성
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		// event의 타입이 SDL_QUIT면 트리거를 활성화 합니다.
		if (event.type == SDL_QUIT) {
			scene.quit = EXIT_GAME;
			break;
		}
	}
}

void Start_Update()
{
	double dt = getDeltaTime();

	// 마우스 위치를 가져옵니다.
	int mouseX, mouseY = 0;
	getCurrentMousePos(&mouseX, &mouseY);


	if (getButtonState(SDL_BUTTON_LEFT) == KEY_DOWN) {
		// startButton이 눌렸는지 체크한다.
		if (checkCollisionWithPoint(scene.rect_startButton, mouseX, mouseY)) {
			printf("GameScene으로 이동합니다. \n");
			scene.quit = GAME_SCENE;
		}
	}
	
}

void Start_Render()
{
	SDL_Renderer* renderer = Get_Renderer();

	// 회색 배경을 칠합니다.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	
	drawTextureWithRatio(renderer, 0,0, 2, 2, scene.img_map);
	drawFilledRectangle(renderer, scene.rect_startButton.x
		, scene.rect_startButton.y
		, scene.rect_startButton.w, scene.rect_startButton.h, 255, 255, 255, 255);
	
	// 오브젝트를 그리는 코드를 작성합니다.

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
	// 필요한 변수를 초기화 합니다.
	// 꼭, 씬에서 계속 사용할 변수는 이곳에서 초기화 합니다.
	scene.quit = SCENE_LOOP;

	// 루프를 진행합니다.
	while (scene.quit == SCENE_LOOP) {
		// 유틸 함수를 업데이트 합니다.
		// 이를 씬별로 수행해야, 여러 함수들을 정상적으로 사용할 수 있습니다.
		Update_Util();

		Start_Event();
		Start_Update();
		Start_Render();
	}

	// 씬의 정보를 확인해서 내보냅니다.
	return scene.quit;
}
