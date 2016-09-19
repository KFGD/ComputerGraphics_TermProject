#pragma once
#include "Scene.h"

class CBaseSceneManager
{
public:
	void SetUpScene(ID3D11DeviceContext* immediateContext, IDXGISwapChain* dxgiSwapChain, ID3D11RenderTargetView* renderTargerView);
	void StartScene();
	void UpdateScene();
	void AddScene(CScene* scene);
	void SelectScene(int index);
	
private:
	std::vector<CScene*> sceneList;
	CScene* currentScene;
	
public:
	CBaseSceneManager();
	~CBaseSceneManager();
};

