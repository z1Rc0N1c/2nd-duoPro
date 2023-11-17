#include "pch.h"
#include "timer.h"

Uint64 beforeTicks;
Uint64 currentTicks;
Uint64 elapsedTicks;
double deltaTime;

void initTimer()
{
	beforeTicks = SDL_GetPerformanceCounter();
	currentTicks = SDL_GetPerformanceCounter();
	elapsedTicks = 0;
	deltaTime = 0;
}

// ������ �� �ð� ������ �� ���� ���մϴ�.
void updateTimer()
{
	beforeTicks = currentTicks;
	currentTicks = SDL_GetPerformanceCounter();
	elapsedTicks = currentTicks - beforeTicks;

	// ���� �����ӿ� ����
	deltaTime = (double)elapsedTicks / SDL_GetPerformanceFrequency();
}

double getDeltaTime()
{
	return deltaTime;
}
