#include "stdafx.h"
#include "Framework.h"
#include "TestScene.h"

int main()
{
	Framework* f = new Framework;
	//���� Scene, ���� Ÿ��Ʋ, �ػ�(����, ����), â��� ���θ� �����մϴ�.
	f->Run(new TestScene(),L"Ÿ��Ʋ", 800,600, false);
	SAFE_DELETE(f);

	return 0;
}