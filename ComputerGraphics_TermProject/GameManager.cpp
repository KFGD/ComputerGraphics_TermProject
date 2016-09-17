#include "GameManager.h"



CGameManager * CGameManager::CreateGameManager(HWND hWnd, CBaseDeviceManager* deviceManager, CBaseSceneManager* sceneManager)
{
	CGameManager* gameManager = new CGameManager();
	gameManager->deviceManager = deviceManager;
	gameManager->sceneManager = sceneManager;
	return gameManager;
}

void CGameManager::GameLoop()
{/*
	sceneManager->UpdateSceneElements();*/
}

CGameManager::CGameManager()
{
}


CGameManager::~CGameManager()
{
}
