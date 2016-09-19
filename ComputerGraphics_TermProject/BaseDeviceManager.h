#pragma once
#include <d3d11.h>
#include <dxgi.h>
#include "GameObject.h"

class CBaseDeviceManager
{
public:
	bool InitializeDirect3D(HWND hWnd);
	void UninitializeDirect3D();

protected:
	//InitializeDirect3D
	bool CreateDeviceAndSwapChain(HWND hWnd);
	bool CreateRenderTargetView();
	bool CreateDepthStencilBufferAndBuffer();
	void SetRenderTargets();
	void SetViewports();


public:
	//InitializeDirect3D
	ID3D11Device* d3dDevice = nullptr;				//하드웨어의 기능 지원 점검과 자원 할당에 사용되는 인터페이스
	ID3D11DeviceContext* immediateContext = nullptr;	//렌더 대상 설정 및 자원을 그래픽 파이프라인에 바인딩하고 GPU가 수행할 렌더링 명령들을 지시하는 데에 사용되는 인터페이스
	IDXGISwapChain* dxgiSwapChain = nullptr;
	//텍스처는 PipeLine으로부터 View를 통해서 Access가 가능함, Render-Target도 텍스처의 일종이기 때문에 역시 View를 이용하여 Access해야 한다
	ID3D11RenderTargetView* renderTargetView = nullptr;	//Render-Target-View

public:
	CBaseDeviceManager();
	virtual ~CBaseDeviceManager();
};

