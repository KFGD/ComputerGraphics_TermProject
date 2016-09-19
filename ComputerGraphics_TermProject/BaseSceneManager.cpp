#include "BaseSceneManager.h"


void CBaseSceneManager::SetUpScene(ID3D11DeviceContext * immediateContext, IDXGISwapChain * dxgiSwapChain, ID3D11RenderTargetView * renderTargerView)
{
	currentScene->SetUp(immediateContext, dxgiSwapChain, renderTargerView);
}

void CBaseSceneManager::StartScene()
{
	currentScene->Awake();
	currentScene->Start();
}

void CBaseSceneManager::UpdateScene()
{
	currentScene->Update();
}

void CBaseSceneManager::AddScene(CScene * scene)
{
	sceneList.push_back(scene);
}

void CBaseSceneManager::SelectScene(int index)
{
	currentScene = sceneList.at(index);
}


CBaseSceneManager::CBaseSceneManager()
{
}


CBaseSceneManager::~CBaseSceneManager()
{
}

