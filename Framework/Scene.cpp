#include "stdafx.h"
#include "Scene.h"
#include "Framework.h"
#include "GameObject.h"

Scene* Scene::currentScene = nullptr;
Scene* Scene::nextScene = nullptr;

Scene::Scene(): renderingManager(nullptr), camera(nullptr)
{
}

Scene::~Scene()
{
	for (auto& i : gameObjectList)
	{
		SAFE_DELETE(i);
	}
	gameObjectList.clear();
	renderableList.clear();
	SAFE_DELETE(renderingManager);
	SAFE_DELETE(collisionManager);
}

void Scene::SwapScene(D2DApp* d2dApp)
{
	if (!nextScene)
		return;

	SAFE_DELETE(currentScene);
	currentScene = nextScene;
	nextScene = nullptr;

	currentScene->renderingManager = new RenderingManager(d2dApp);
	currentScene->collisionManager = new CollisionManager();
	currentScene->camera = new Camera();
	currentScene->Push(currentScene->camera);
	currentScene->Initialize();
}

void Scene::ChangeScene(Scene* nextScene)
{
	Scene::nextScene = nextScene;
}

Scene* Scene::GetCurrentScene()
{
	return Scene::currentScene;
}

void Scene::PushOnCurrentScene(GameObject* gameObject)
{
	if (currentScene)
		currentScene->Push(gameObject);
	else
		std::cout << "Scene::PushObject error: ���� ���� �����ϴ�.\n";
}

void Scene::PushOnCurrentScene(AABBCollider* col)
{
	if (currentScene)
	{
		if (currentScene->collisionManager)
			currentScene->collisionManager->PushBackCollider(col);		
		else
			std::cout << "Scene::PushObject: collisionManager�� �����ϴ�.\n";		
	}
	else
	{
		std::cout << "Scene::PushObject: ���� ���� �����ϴ�.\n";
	}

}

void Scene::Initialize()
{
	GameObject* g = Push(new GameObject(L"a.png"));
	g->transform->SetPosition(100.0f, 100.0f);
}

void Scene::UpdateGameObjects()
{
	//��� ������Ʈ�� Update�� ����
	for (auto& i : gameObjectList)
		if (i->isActive)
			i->Update();

	//LateUpdate ����
	for (auto& i : gameObjectList)
		if (i->isActive)
			i->LateUpdate();
}

void Scene::UpdatePhysics()
{
	collisionManager->Update();
}

void Scene::DeleteDestroyedObjects()
{
	//���� ��û���� ������Ʈ ����
	auto i = destroyedObjectList.begin();
	while (i != destroyedObjectList.end())
	{
		(*i)->OnDestroy();
		gameObjectList.remove(*i);		//���ӿ�����Ʈ����Ʈ���� ����
		renderableList.remove(*i);		//�������� ����Ʈ���� ����
		collisionManager->RemoveGameObject(*i);
		GameObject* t = *i;
		SAFE_DELETE(t);				//delete
		destroyedObjectList.remove(*i);
		i = destroyedObjectList.begin();
	}
	destroyedObjectList.clear();
}

void Scene::Render()
{
	renderingManager->BeginRender();
	for (auto& i : renderableList)
		renderingManager->Render(i->renderer, i->transform,camera->transform->position);
		//renderingManager->Render(i->renderer, i->transform);
	renderingManager->EndRender();
}

GameObject* Scene::Push(GameObject* gameObject)
{
	//���� ������Ʈ�� �������
	gameObjectList.push_back(gameObject);
	//�������� �̹����� �������
	//�������� ����Ʈ�� �������
	if (gameObject->renderer->GetInitialized())
	{
		renderableList.push_back(gameObject);
	}
	return gameObject;//���� ���ӿ�����Ʈ�� �״�� ��ȯ
}

void Scene::Destroy(GameObject* o)
{
	//������ ������Ʈ ����Ʈ�� �������
	if (currentScene)
	{
		currentScene->destroyedObjectList.push_back(o);
	}
	else
	{
		std::cout << "Scene::Destroy ���� ���� �����ϴ�.\n";
	}
}

RenderingManager* Scene::GetRenderingManager()
{
	return renderingManager;
}

CollisionManager* Scene::GetCollisionManager()
{
	return collisionManager;
}

Camera* Scene::GetCamera()
{
	return camera;
}
