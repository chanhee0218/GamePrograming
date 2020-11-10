#include "stdafx.h"
#include "CollisionManager.h"

CollisionManager::~CollisionManager()
{
	//Collider의 instance는 게임오브젝트에서 각자 삭제처리 해주는 것으로 간주합니다.
	aabbList.clear();
}

void CollisionManager::PushBackCollider(AABBCollider* col)
{
	aabbList.push_back(col);
	gameObjectList.push_back(col->target);
}

void CollisionManager::RemoveGameObject(GameObject* g)
{
	gameObjectList.remove(g);
	std::list<AABBCollider*>::iterator iter = aabbList.begin();
	for (; iter != aabbList.end(); iter++)
	{
		if ((*iter)->target == g)
		{
			aabbList.erase(iter);
			break;
		}
	}
}

void CollisionManager::Update()
{
	//충돌 처리
	for (std::list<AABBCollider*>::iterator i = aabbList.begin();
		i!=aabbList.end(); i++)
	{
		std::list<AABBCollider*>::iterator j = i;
		j++;
		for (; j != aabbList.end(); j++)
		{
			if ((*i)->Intersected((*j)))
			{
				(*i)->target->OnCollision((*j)->target);
				(*j)->target->OnCollision((*i)->target);
			}
		}
	}
}
	