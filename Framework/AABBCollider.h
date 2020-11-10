#pragma once
#include "Collider.h"

class AABBCollider : public Collider
{
private:
	Transform* transform;
public:
	float left;
	float right;
	float top;
	float bottom;

	bool Intersected(AABBCollider* col);

	AABBCollider(GameObject* target, float width, float height);
	AABBCollider(GameObject* target, Sprite* sprite);
	AABBCollider(GameObject* target, RenderInfo* renderer);
	AABBCollider(GameObject* target, float left, float bottom, float right, float top);
	~AABBCollider();
};

