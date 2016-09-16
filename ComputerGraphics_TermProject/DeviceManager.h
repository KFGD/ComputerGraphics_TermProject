#pragma once
#include <d3d11.h>
#include <dxgi.h>

class CDeviceManager
{
public:
	static CDeviceManager* CreateDeviceManager(HWND hWnd);
	bool InitializeDirect3D(HWND hWnd);
	void UninitializeDirect3D();
	bool CreateVertexShader(const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11VertexShader **ppVertexShader);
	bool CreatePixelShader(const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11PixelShader **ppPixelShader);

private:
	//InitializeDirect3D
	bool CreateDeviceAndSwapChain(HWND hWnd);
	bool CreateRenderTargetView();
	bool CreateDepthStencilBufferAndBuffer();
	void SetRenderTargets();
	void SetViewports();


private:
	//InitializeDirect3D
	ID3D11Device* d3dDevice = nullptr;				//�ϵ������ ��� ���� ���˰� �ڿ� �Ҵ翡 ���Ǵ� �������̽�
	ID3D11DeviceContext* immediateContext = nullptr;	//���� ��� ���� �� �ڿ��� �׷��� ���������ο� ���ε��ϰ� GPU�� ������ ������ ��ɵ��� �����ϴ� ���� ���Ǵ� �������̽�
	IDXGISwapChain* dxgiSwapChain = nullptr;
	//�ؽ�ó�� PipeLine���κ��� View�� ���ؼ� Access�� ������, Render-Target�� �ؽ�ó�� �����̱� ������ ���� View�� �̿��Ͽ� Access�ؾ� �Ѵ�
	ID3D11RenderTargetView* renderTargetView = nullptr;	//Render-Target-View

private:
	CDeviceManager();
public:
	~CDeviceManager();
};

