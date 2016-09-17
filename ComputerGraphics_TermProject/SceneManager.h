#pragma once
#include "BaseSceneManager.h"

class CSceneManager : public CBaseSceneManager
{
public:
	// CBaseSceneManager��(��) ���� ��ӵ�
	virtual void UpdateSceneElements(ID3D11DeviceContext* immediataContext) override;
	virtual void RenderSceneElements(ID3D11DeviceContext * immediateContext, IDXGISwapChain* dxgiSwapChain, ID3D11RenderTargetView* renderTargetView) override;

public:
	CSceneManager();
	~CSceneManager();

};

