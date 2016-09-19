#pragma once
#include "BaseDeviceManager.h"
#include "BaseSceneManager.h"


class CGameManager
{
public:
	static CGameManager* CreateGameManager(HWND hWnd, CBaseDeviceManager* deviceManager, CBaseSceneManager* sceneManager);
	void Run();
	void Destroy();
private:
	void GameLoop();
private:
	HWND hWnd;
	CBaseDeviceManager* deviceManager;
	CBaseSceneManager* sceneManager;
	bool isRunning = false;
private:
	CGameManager();
public:
	~CGameManager();
};

