#include "pch.h"
#include "SampleScene.h" // include!

// �ʿ��� ������ ���� ������ �����ؼ� ����մϴ�.
typedef struct SampleScene {
	// ������ ���������� ����� ������ ����ü�� �����ؼ� ����մϴ�.
	int quit;
} SampleScene;
SampleScene sampleScene;

void SampleScene_Init()
{
	SDL_Renderer* renderer = Get_Renderer();
}

void SampleScene_Event()
{
	// SDL �̺�Ʈ�� Ȯ���ϱ� ���� ��ü ����
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		// event�� Ÿ���� SDL_QUIT�� Ʈ���Ÿ� Ȱ��ȭ �մϴ�.
		if (event.type == SDL_QUIT) {
			sampleScene.quit = EXIT_GAME;
			break;
		}
	}
}

void SampleScene_Update()
{
	double dt = getDeltaTime();

	// ������Ʈ�� �̵��� ó���ϴ� �ڵ带 �ۼ��մϴ�.
}

void SampleScene_Render()
{
	SDL_Renderer* renderer = Get_Renderer();

	// ȸ�� ����� ĥ�մϴ�.
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 50);
	SDL_RenderClear(renderer);

	drawTexture(renderer, 0, 0, loadTexture(renderer, "D:\Coding\VisualStudio\ZOMVILLE\Sunrin_SDL_Project\resources"));

	// ������Ʈ�� �׸��� �ڵ带 �ۼ��մϴ�.

	SDL_RenderPresent(renderer);
}

void SampleScene_Release()
{
	// ����� �ڷḦ �����մϴ�.

}

int SampleScene_Loop()
{
	// �ʿ��� ������ �ʱ�ȭ �մϴ�.
	// ��, ������ ��� ����� ������ �̰����� �ʱ�ȭ �մϴ�.
	sampleScene.quit = SCENE_LOOP;

	// ������ �����մϴ�.
	while (sampleScene.quit == SCENE_LOOP) {
		// ��ƿ �Լ��� ������Ʈ �մϴ�.
		// �̸� ������ �����ؾ�, ���� �Լ����� ���������� ����� �� �ֽ��ϴ�.
		Update_Util();

		SampleScene_Event();
		SampleScene_Update();
		SampleScene_Render();
	}

	// ���� ������ Ȯ���ؼ� �������ϴ�.
	return sampleScene.quit;
}
