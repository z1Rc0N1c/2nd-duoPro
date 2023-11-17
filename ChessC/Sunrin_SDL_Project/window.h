#pragma once
#include <SDL.h>

// �� ���� ������ ���ؼ�, �Ʒ��� �� ��ȣ�� �����մϴ�.
#define EXIT_GAME		-1
#define SCENE_LOOP		-2
#define START_SCENE		1
#define GAME_SCENE		2
#define MAIN_SCENE		0

// ȭ���� ũ�⸦ �����մϴ�.
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900


// ���α׷��� �ʱ�ȭ�� ���⼭ �����մϴ�.
// ���̺귯�� �ʱ�ȭ ����, �ش� �Լ����� ����˴ϴ�.
// ����, �ٸ� ��ġ���� ���̺귯�� �ʱ�ȭ �Լ��� ������ �ʿ䰡 �����ϴ�.
int Init_Program();

// ��ƿ��Ƽ ���� ������Ʈ �մϴ�.
void Update_Util();

// �ʿ��� �ڷḦ �޾ƿ� �� �ִ� Getter�� �����մϴ�.
SDL_Window* Get_Window();

SDL_Surface* Get_Renderer();

// ����� �ڷ��� ����� �����մϴ�.
void Release_Program();