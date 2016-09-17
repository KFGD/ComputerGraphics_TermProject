#pragma once
#include "BaseDeviceManager.h"
#include "BaseSceneManager.h"

class CGameManager
{
public:
	static CGameManager* CreateGameManager(HWND hWnd, CBaseDeviceManager* deviceManager, CBaseSceneManager* sceneManager);
private:
	void GameLoop();
private:
	CBaseDeviceManager* deviceManager;
	CBaseSceneManager* sceneManager;
private:
	CGameManager();
public:
	~CGameManager();
};

