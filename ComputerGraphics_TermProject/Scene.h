#pragma once
#include "GameObject.h"
#include <vector>

class CScene
{
public:
	void SetUp(ID3D11DeviceContext* immediateContext, IDXGISwapChain* dxgiSwapChain, ID3D11RenderTargetView* renderTargerView);
public:
	void Awake();
	void Start();
	void Update();
	
protected:
	std::vector<CGameObject*> objectList;

private:
	//From: BaseDeviceManager
	ID3D11DeviceContext* immediateContext;
	IDXGISwapChain* dxgiSwapChain;
	ID3D11RenderTargetView* renderTargetView;
public:
	CScene();
	~CScene();
};

