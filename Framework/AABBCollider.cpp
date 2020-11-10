#include "stdafx.h"
#include "AABBCollider.h"


AABBCollider::AABBCollider(GameObject* target, float width, float height)
	:Collider(target)
{
	left = -width * 0.5f;
	right = width * 0.5f;
	top = height * 0.5f;
	bottom = -height * 0.5f;
	transform = target->transform;
}

AABBCollider::AABBCollider(GameObject* target, Sprite* sprite)
	:Collider(target)
{
	transform = target->transform;
	left = (float)(sprite->bitmap->GetPixelSize().width)*(-1.0f) * 0.5f;
	right = (float)sprite->bitmap->GetPixelSize().width * 0.5f;
	top = (float)sprite->bitmap->GetPixelSize().height * 0.5f;
	bottom = (float)(sprite->bitmap->GetPixelSize().height)*(-1.0f) * 0.5f;
}

AABBCollider::AABBCollider(GameObject* target, RenderInfo* renderer)
	:Collider(target)
{
	transform = target->transform;
	left = (float)(-renderer->GetWidth() * 0.5f);
	right = (float)renderer->GetWidth() * 0.5f;
	top = (float)renderer->GetHeight() * 0.5f;
	bottom = (float)(-renderer->GetHeight() * 0.5f);
}

AABBCollider::AABBCollider(GameObject* target,
	float left, float bottom, float right, float top)
	: Collider(target), left(left), right(right), top(top), bottom(bottom), transform(target->transform)
{
}

bool AABBCollider::Intersected(AABBCollider* other)
{
	float aLeft, bLeft;
	float aRight, bRight;
	float aTop, bTop;
	float aBottom, bBottom;
	aLeft = left * transform->scale.x
		+ transform->position.x;
	aRight = right * transform->scale.x
		+ transform->position.x;
	aTop = top * transform->scale.y
		+ transform->position.y;
	aBottom = bottom * transform->scale.y
		+ transform->position.y;
	bLeft = other->left * other->transform->scale.x
		+ other->transform->position.x;
	bRight = other->right * other->transform->scale.x
		+ other->transform->position.x;
	bTop = other->top * other->transform->scale.y
		+ other->transform->position.y;
	bBottom = other->bottom * other->transform->scale.y
		+ other->transform->position.y;

	return
		!(
		(aRight < bLeft) || (bRight < aLeft) ||
			(aBottom > bTop) || (bBottom > aTop)
			);
}


AABBCollider::~AABBCollider()
{
}
