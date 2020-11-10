#include "stdafx.h"
#include "Camera.h"
#include "Scene.h"

#include "InputManager.h"
#include "TimeManager.h"

Camera::Camera()
{
	screenWidth = WinApp::GetScreenWidth();
	screenHeight = WinApp::GetScreenHeight();
	halfWidth = (float)screenWidth * 0.5f;
	halfHeight = (float)screenHeight * 0.5f;

	screenBox = new AABBCollider(this, -halfWidth,  -halfHeight, halfWidth, halfHeight);
	printf("w: %f, h: %f\n", halfWidth, halfHeight);
}

Camera::~Camera()
{
	SAFE_DELETE(screenBox);
}

Vector2 Camera::WorldPositionToScreen(const Vector2& worldPos)
{
	//piw: ���� ������
	//cp: ī�޶� ������
	//ss: ȭ�� ũ��(����,����)
	//pis: ��ũ�� ������
	//piw - cp + ss/2 = pis

	//y���� ���� ���Ұ��
	Camera* current = Camera::GetCamera();
	return Vector2(
		current->halfWidth - worldPos.x + current->transform->position.x,
		current->halfHeight - worldPos.y + current->transform->position.y
	);
	//y���� �Ʒ��� ���Ұ��
	//return Vector2(
	//	worldPos.x - transform->position.x + halfWidth * 0.5f,
	//	worldPos.y - transform->position.x + halfWidth * 0.5f);
}

Vector2 Camera::ScreenPositionToWorld(const Vector2& screenPos)
{
	//��������ũ���̶� �ݴ���ϸ��

	//y���� ���� ���Ұ��
	Camera* current = Camera::GetCamera();
	return Vector2(
		screenPos.x - current->halfWidth + current->transform->position.x,
		current->halfHeight - screenPos.y + current->transform->position.y
	);

	//y���� �Ʒ��� ���Ұ��
	/*return Vector2(
		screenPos.x - halfWidth + transform->position.x,
		screenPos.y - halfHeight + transform->position.y
		);*/
}

bool Camera::IsOnScreen(AABBCollider* col)
{
	return col->Intersected(screenBox);
}

Camera* Camera::GetCamera()
{
	return Scene::GetCurrentScene()->GetCamera();
}

void Camera::Update()
{
	////�������� ���
	/*if (InputManager::GetKeyState('W'))
		transform->position.y += 100.0f * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState('S'))
		transform->position.y -= 100.0f * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState('D'))
		transform->position.x += 100.0f * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState('A'))
		transform->position.x -= 100.0f * TimeManager::GetDeltaTime();*/
}
