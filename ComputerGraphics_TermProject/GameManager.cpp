#include "GameManager.h"



CGameManager * CGameManager::CreateGameManager(HWND hWnd, CBaseDeviceManager* deviceManager, CBaseSceneManager* sceneManager)
{
	CGameManager* gameManager = new CGameManager();
	gameManager->hWnd = hWnd;
	gameManager->deviceManager = deviceManager;
	gameManager->sceneManager = sceneManager;
	return gameManager;
}

void CGameManager::Run()
{
	sceneManager->SelectScene(0);
	sceneManager->SetUpScene(deviceManager->immediateContext, deviceManager->dxgiSwapChain, deviceManager->renderTargetView);
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	isRunning = true;
	GameLoop();
}

void CGameManager::Destroy()
{
	deviceManager->UninitializeDirect3D();
}

void CGameManager::GameLoop()
{
	MSG msg;
	while (isRunning)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&msg, nullptr, 0, 0))
				return;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			sceneManager->UpdateScene();
			Sleep(1);
		}
	}
}

CGameManager::CGameManager()
{
}


CGameManager::~CGameManager()
{
	if (nullptr != sceneManager)
		delete sceneManager;
	if (nullptr != deviceManager)
		delete deviceManager;
}
