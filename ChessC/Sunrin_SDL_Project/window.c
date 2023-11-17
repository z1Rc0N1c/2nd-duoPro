#include "pch.h"
#include "window.h"

// ������ ��ü�� ���� �����͸� �����մϴ�.
SDL_Window* window = NULL;

// �������� ����� �����͸� �����մϴ�.
SDL_Surface* renderer = NULL;


int Init_Program()
{
    // SDL �ʱ�ȭ
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL �ʱ�ȭ�� �����߽��ϴ�: %s\n", SDL_GetError());
        return 1;
    }

    // �̹��� �ʱ�ȭ
    if (initImage() != 0) {
        SDL_Quit();
        return 1;
    }

    // ����� �ʱ�ȭ�� �����մϴ�.
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096)) {
        printf("Audio �ʱ�ȭ�� �����߽��ϴ�: %s \n", Mix_GetError());
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // ��Ʈ ���̺귯�� �ʱ�ȭ�� �����մϴ�.
    if (TTF_Init() < 0) {
        printf("��Ʈ�� �ʱ�ȭ�� �� �����ϴ�: %s \n", TTF_GetError());
        IMG_Quit();
        SDL_Quit();
        Mix_Quit();
        return 1;
    }

    // ������ ����
    // SDL_CreateWindow(u8"SDL ������Ʈ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0)
    // ������ â�� title, x, y, w, h, flag�� ������.
    // Tips: u8"" �� �ؽ�Ʈ�� UTF-8 �������� ���ڵ� �մϴ�.
    window = SDL_CreateWindow(u8"SDL ������Ʈ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window) {
        printf("�����츦 ������ �� �����ϴ�: %s\n", SDL_GetError());
        IMG_Quit();
        Mix_Quit();
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // ������ ����
    // ������ �۾��� ������ �������� �����մϴ�.
    // â���� �������� �����մϴ�.
    // SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // -1: ���� ù��°�� ��� ������ �׷��� ����̹� ���
    // SDL_RENDERER_ACCELERATED: �ϵ���� ����
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("�������� ������ �� �����ϴ�: %s\n", SDL_GetError());
        IMG_Quit();
        Mix_Quit();
        TTF_Quit();
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Ÿ�̸� �ʱ�ȭ
    initTimer();

    // ���� �Լ� �ʱ�ȭ
    srand(time(NULL));

    return 0;
}

void Update_Util()
{
    // �Է� �Լ��� ������Ʈ �մϴ�.
    updateKeyState();
    updateMouseState();

    // Ÿ�̸� �Լ��� ������Ʈ �մϴ�.
    updateTimer();
}

SDL_Window* Get_Window()
{
    if (window == NULL) {
        printf("Window�� �ʱ�ȭ���� �ʾҽ��ϴ�.");
        return NULL;
    }

    return window;
}

SDL_Surface* Get_Renderer()
{
    if (renderer == NULL) {
        printf("Renderer�� �ʱ�ȭ���� �ʾҽ��ϴ�.");
        return NULL;
    }

    return renderer;
}

void Release_Program()
{
    // 	window, renderer, library ���� �����մϴ�.
    // â�� �� ���� ������ ����� �޸𸮸� �������־�� �մϴ�.
    // ������� ������, �����츦 �����ϰ�, SDL�� �����ŵ�ϴ�.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}