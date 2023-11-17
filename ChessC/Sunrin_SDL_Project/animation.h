#pragma once
#include <SDL_image.h>
#include "linkedList.h"

#define ANIM_LOOP_OFF	0
#define ANIM_LOOP_ON	1

typedef struct Animatnion {
	List animList;		// ����� �̹��� ��ü�� ��Ƶδ� �� �Դϴ�.
	double animTimer;	// ����� �̹����� ��ȯ�ϱ� ���� Ÿ�̸� �Դϴ�.
	
	int currentFrame;		// ���� ����� �̹����� �ε����� �ǹ��մϴ�.
	int fps;				// 1�ʿ� �̹����� �� �� �ѱ� �������� �ǹ��մϴ�.
	int isLoop;				// �ݺ� ���θ� �ǹ��մϴ�.
	int end;				// ���� ���θ� �ǹ��մϴ�.
} Animation;

// Animation�� �ʱ�ȭ �մϴ�.
// fps: 1�ʿ� �̹����� �� �� �ѱ� ������ �ۼ��մϴ�.
// isLoop: �̹����� �ݺ��� ������ �ۼ��մϴ�. (ANIM_LOOP_OFF, ON�� Ȱ���� ������.)
void initAnimation(Animation* anim, int fps, int isLoop);

// Animation�� ����� �մϴ�.
// currentFrameIndex, animTimer, end�� �ʱ�ȭ �մϴ�.
void restartAnimation(Animation* anim);

// Animation�� ���� �մϴ�.
// �̸� ������ ���� Animation�� ���ο� ��ü�� �����ϱ� ���� ����մϴ�.
void copyAnimation(Animation* dst, Animation* src);

// Animation�� �ؽ��ĸ� �߰��մϴ�.
void appendTexture(Animation* anim, SDL_Texture* texture);

// Animation�� Ÿ�̸Ӹ� ������Ʈ�Ͽ�, ���� �̹����� ���մϴ�.
void updateAnimation(Animation* anim, double dt);
 
// ���� �������� �̹����� ���մϴ�.
SDL_Texture* getCurrentFrame(Animation* anim);

// Animation�� �����մϴ�.
// ������ �����ϸ� �˴ϴ�.
void releaseAnimation(Animation* anim);

// Animationn�� �����մϴ�.
// ������ �����ϸ� �˴ϴ�.
// Texture ���� ���⼭ �����ϰ� �ʹٸ�, �Ʒ� �Լ��� ������ּ���.
void releaseAnimationWTexture(Animation* anim);