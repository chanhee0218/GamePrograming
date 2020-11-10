#pragma once
#include "Transform.h"
#include "GameObject.h"
class Collider
{
public:
	Collider(GameObject* target);
public:
	GameObject* target;
};

