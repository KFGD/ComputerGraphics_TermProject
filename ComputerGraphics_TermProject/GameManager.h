#pragma once
#include "DeviceManager.h"
#include "SceneManager.h"

class CGameManager
{
public:
	static CGameManager* CreateGameManager(HWND hWnd);
private:
	bool InitializeGameManager(HWND hWnd);
private:
	CDeviceManager* deviceManager;
	CSceneManager* sceneManager;
private:
	CGameManager();
public:
	~CGameManager();
};

