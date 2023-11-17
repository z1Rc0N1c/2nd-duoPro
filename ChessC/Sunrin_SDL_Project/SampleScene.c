#include "pch.h"
#include "SampleScene.h" // include!

// 필요한 변수는 전역 변수로 전언해서 사용합니다.
typedef struct SampleScene {
	// 씬에서 전역적으로 사용할 변수는 구조체로 랩핑해서 사용합니다.
	int quit;
} SampleScene;
SampleScene sampleScene;

void SampleScene_Init()
{
	SDL_Renderer* renderer = Get_Renderer();
}

void SampleScene_Event()
{
	// SDL 이벤트를 확인하기 위한 객체 생성
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		// event의 타입이 SDL_QUIT면 트리거를 활성화 합니다.
		if (event.type == SDL_QUIT) {
			sampleScene.quit = EXIT_GAME;
			break;
		}
	}
}

void SampleScene_Update()
{
	double dt = getDeltaTime();

	// 오브젝트의 이동을 처리하는 코드를 작성합니다.
}

void SampleScene_Render()
{
	SDL_Renderer* renderer = Get_Renderer();

	// 회색 배경을 칠합니다.
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 50);
	SDL_RenderClear(renderer);

	drawTexture(renderer, 0, 0, loadTexture(renderer, "D:\Coding\VisualStudio\ZOMVILLE\Sunrin_SDL_Project\resources"));

	// 오브젝트를 그리는 코드를 작성합니다.

	SDL_RenderPresent(renderer);
}

void SampleScene_Release()
{
	// 사용한 자료를 해제합니다.

}

int SampleScene_Loop()
{
	// 필요한 변수를 초기화 합니다.
	// 꼭, 씬에서 계속 사용할 변수는 이곳에서 초기화 합니다.
	sampleScene.quit = SCENE_LOOP;

	// 루프를 진행합니다.
	while (sampleScene.quit == SCENE_LOOP) {
		// 유틸 함수를 업데이트 합니다.
		// 이를 씬별로 수행해야, 여러 함수들을 정상적으로 사용할 수 있습니다.
		Update_Util();

		SampleScene_Event();
		SampleScene_Update();
		SampleScene_Render();
	}

	// 씬의 정보를 확인해서 내보냅니다.
	return sampleScene.quit;
}
