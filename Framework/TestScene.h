#pragma once
#include "Scene.h"
#include "AnimationObject.h"
class TestScene :
	public Scene
{
public:
	virtual void Initialize();	//�����ڰ� �ƴ�, Initialize�Լ����� �ʱ�ȭ�� �����մϴ�.
								//ChangeScene���� �ڵ尡 ���̴� ���� �����մϴ�.

	AnimationObject* testObject;

};

