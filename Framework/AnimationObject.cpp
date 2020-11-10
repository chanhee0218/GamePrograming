#include "stdafx.h"
#include "AnimationObject.h"
#include "InputManager.h"
#include "TimeManager.h"

AnimationObject::AnimationObject(AnimationInfo* animInfo)
	:GameObject(animInfo)		//'[1]'
{
	//�ִϸ��̼� ���� ���
	//ListAnimation(���� ���������� �ִϸ��̼��� ����)
	//SheetAnimation(���� ������ �߶� �ִϸ��̼��� ����, �ִϸ��̼� ��Ʈ ����)
	//�� �ִϸ��̼� �� �ϳ��� �����Ҵ��� ���� ����
	//Animation Ŭ������ �� �ִϸ��̼��� ����ϴ� Ŭ�����Դϴ�.
	//ó�� �μ� state�� �ִϸ��̼� ��� ��ȣ�� �ǹ��մϴ�.(enum������ ���� ����)
	//state ���� ��ġ�� �ʰ� ���ּ���.

	//AnimationInfo Ŭ������ �ִϸ��̼ǵ��� �����ϰ�, �������� ������ ���� Ŭ�����Դϴ�.
	//�ش� Ŭ������ ����ϱ� ����, �ݵ�� GameObject�� �����ڿ� AnimationInfo�� �����Ͽ��� �մϴ�. '[1]����'
	this->animationRenderer = animInfo;

	//List Animation�Դϴ�. �����Ҵ����ݴϴ�.
	testAnim1 = new ListAnimation(0,2.0f);				//state���� 0, �ʴ� 2.0������ ������ �ִϸ��̼��Դϴ�.
	testAnim1->PushBackSprite(L"resources/circle.png");	//����� �̹����� pushback ���ݴϴ�.
	testAnim1->PushBackSprite(L"resources/square.png");
	animationRenderer->PushBackAnimation(testAnim1);	//AnimationInfo�� �ִϸ��̼��� Ǫ�����մϴ�.

	//Sheet Animation�Դϴ�.
	//state���� 1, �ʴ� 16.0������ ������ �ִϸ��̼��Դϴ�.
	//sheet �ִϸ��̼ǿ� ���� �ϳ��� �̹��� ���ϸ��� �ʿ��ϹǷ� �����ڿ��� �̹����� �ε����ݴϴ�.
	//row���� sheet�� �� �ٿ� ����� �̹����� �� �Դϴ�.
	//length�� sheet�� ����� ��� �̹����� �� �Դϴ�.
	testAnim2 = new SheetAnimation(1, 16.0f, L"resources/sheet.png", 4, 16);
	animationRenderer->PushBackAnimation(testAnim2);//AnimationInfo�� �ִϸ��̼��� Ǫ�����մϴ�.

	moveSpeed = 100.0f;	//�̵� �׽�Ʈ
}

void AnimationObject::Update()
{
	//�������� ����ϴ� �κ��Դϴ�.
	//InputManager::GetKey~�Լ��� ���� �Է��� üũ�� �� �ֽ��ϴ�.
	//4���� ���� ������ �����ϼ���.
	if (InputManager::GetKeyState(VK_UP))
		transform->position.y -= moveSpeed * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState(VK_DOWN))
		transform->position.y += moveSpeed * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState(VK_RIGHT))
		transform->position.x += moveSpeed * TimeManager::GetDeltaTime();
	if (InputManager::GetKeyState(VK_LEFT))
		transform->position.x -= moveSpeed * TimeManager::GetDeltaTime();

	//Scene ������ ����ϴ� �κ��Դϴ�.
	if (InputManager::GetKeyDown(VK_RETURN))
	{
		//���� Scene���� ������ �غ� �մϴ�.
		//�Ʒ��� ���� ���·� ȣ���Ͽ� �ݴϴ�.
		//�ѹ��� ChangeScene�� ������ ȣ������ �ʵ��� ������ �ּ���.
		//Scene::ChangeScene(new GameScene());
	}

	//�ִϸ��̼� ������ ����� �κ��Դϴ�.
	//�ִϸ��̼��� ��ϵǾ��ִٸ�, ó���� ������ state���� ȣ���Ͽ� �ִϸ��̼��� ������ �� �ֽ��ϴ�.
	if (InputManager::GetKeyDown(VK_SPACE))
	{
		static int cur = 0;
		if (cur == 0)
		{
			cur = 1;
			animationRenderer->ChangeAnimation(1);
		}
		else
		{
			cur = 0;
			animationRenderer->ChangeAnimation(0);
		}
	}
}
