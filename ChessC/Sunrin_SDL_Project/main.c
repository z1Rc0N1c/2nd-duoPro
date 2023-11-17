#include "pch.h"
#include "Start.h"
#include "Game.h"

int main() {
	// ���α׷����� ����� ���̺귯�� �ʱ�ȭ ����
	Init_Program();

	// ������ ����� �ڷḦ �ҷ��� �� �ֵ���, ���� Init �Լ��� �����մϴ�.
	Start_Init();
	GameScene_Init();

	// ������ ���� ������ �ֽ��ϴ�.
	int scene_info = START_SCENE;

	// �� ������ ���� �۾��� �̰����� �����մϴ�.
	// -1�� ��ȯ�Ǹ�, ���α׷� ����� �����մϴ�.
	while (scene_info >= 0) {
		switch (scene_info)
		{
		case START_SCENE:
			scene_info = Start_Loop();	// MainScene�� �����մϴ�.
			break;
		case GAME_SCENE:
			scene_info = GameScene_Loop();
			break;
		default:
			scene_info = EXIT_GAME;
			break;
		}
	}
	
	// ������ �ҷ��� �ڷḦ ������ �մϴ�.
	Start_Release();

	// ������ ����
	Release_Program();
	return 0;
}
