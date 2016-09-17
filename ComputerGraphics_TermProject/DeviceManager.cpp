#include "DeviceManager.h"



CDeviceManager::CDeviceManager()
{
}


CDeviceManager::~CDeviceManager()
{
}

CDeviceManager * CDeviceManager::CreateDeviceManager(HWND hWnd)
{
	CDeviceManager* deviceManager = new CDeviceManager();
	bool bReturn = deviceManager->InitializeDirect3D(hWnd);
	if (bReturn)
		return deviceManager;
	else {
		deviceManager->UninitializeDirect3D();
		delete deviceManager;
		return nullptr;
	}
}
