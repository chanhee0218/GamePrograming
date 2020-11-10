#pragma once
#include "stdafx.h"
#include "D2DApp.h"
#include "RenderInfo.h"

class RenderingManager
{
private:
	D2DApp* d2dApp;
	Vector2 screenSize;
	float radToEuler;
public:
	RenderingManager(D2DApp* d2dApp);
	~RenderingManager();
public:
	std::list<Sprite*> spriteList;
	Sprite* LoadBitmapFromFile(PCWSTR uri, UINT destinationWidth, UINT destinationHeight);

	//Scene->Render���� ���
	void BeginRender();
	void Render(RenderInfo* renderInfo, Transform* transform);
	void Render(RenderInfo* renderInfo, Transform* transform, Vector2 cameraPosition);
	void EndRender();
	
};

