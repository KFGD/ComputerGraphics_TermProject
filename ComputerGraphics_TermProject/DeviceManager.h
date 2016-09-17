#pragma once
#include "BaseDeviceManager.h"

class CDeviceManager : public CBaseDeviceManager
{
public:
	static CDeviceManager* CreateDeviceManager(HWND hWnd);

private:
	CDeviceManager();
public:
	~CDeviceManager();

};

