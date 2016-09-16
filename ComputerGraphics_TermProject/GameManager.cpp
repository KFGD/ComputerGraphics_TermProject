#include "GameManager.h"



CGameManager * CGameManager::CreateGameManager(HWND hWnd)
{
	CGameManager* gameManager = new CGameManager();
	if(gameManager->InitializeGameManager(hWnd))
		return gameManager;
	else {
		delete gameManager;
		return nullptr;
	}
}

bool CGameManager::InitializeGameManager(HWND hWnd)
{
	if (nullptr == (deviceManager = CDeviceManager::CreateDeviceManager(hWnd)))
		return false;
	if (nullptr == (sceneManager = CSceneManager::CreateSceneManager()))
		return false;
	return true;
}

CGameManager::CGameManager()
{
}


CGameManager::~CGameManager()
{
}
