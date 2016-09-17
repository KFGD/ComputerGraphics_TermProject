#pragma once
#include "GameObject.h"
#include <vector>
class CBaseSceneManager
{
public:
	virtual void ReadyRendering();
	virtual void UpdateSceneElements(ID3D11DeviceContext* immediateContext) = 0;
	virtual void RenderSceneElements(ID3D11DeviceContext* immediateContext, IDXGISwapChain* dxgiSwapChain) = 0;
	
protected:
	std::vector<CGameObject*> objectList;


public:
	CBaseSceneManager();
	virtual ~CBaseSceneManager();
};

