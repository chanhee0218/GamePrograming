#pragma once
#include "AABBCollider.h"
#include <list>
class CollisionManager
{
public:
	~CollisionManager();
public:
	std::list<GameObject*> gameObjectList;
	std::list<AABBCollider*> aabbList;

public:
	void PushBackCollider(AABBCollider* col);
	void RemoveGameObject(GameObject* g);
public:
	void Update();

};

