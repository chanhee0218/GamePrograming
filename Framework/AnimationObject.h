#pragma once
#include "GameObject.h"
#include "AnimationInfo.h"
#include "ListAnimation.h"
#include "SheetAnimation.h"

class AnimationObject :
	public GameObject
{
public:
	AnimationObject(AnimationInfo* animinfo);

public:
	AnimationInfo* animationRenderer;

	ListAnimation* testAnim1;
	SheetAnimation* testAnim2;

	float moveSpeed;
public:
	virtual void Update();
};

