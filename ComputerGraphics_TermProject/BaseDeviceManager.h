#pragma once
#include <d3d11.h>
#include <dxgi.h>
#include "GameObject.h"

class CBaseDeviceManager
{
public:
	bool InitializeDirect3D(HWND hWnd);
	void UninitializeDirect3D();
	bool CreateVertexShader(const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11VertexShader **ppVertexShader);
	bool CreatePixelShader(const void* pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage* pClassLinkage, ID3D11PixelShader **ppPixelShader);
	bool CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs, UINT NumElements, const void* pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength, ID3D11InputLayout** ppInputLayout);
	bool CreateVertexShaderFromCSOFile(const char* fileName, CRendering* rendering);
	bool CreatePixelShaderFromCSOFile(const char* fileName, CRendering* rendering);

protected:
	//InitializeDirect3D
	bool CreateDeviceAndSwapChain(HWND hWnd);
	bool CreateRenderTargetView();
	bool CreateDepthStencilBufferAndBuffer();
	void SetRenderTargets();
	void SetViewports();


protected:
	//InitializeDirect3D
	ID3D11Device* d3dDevice = nullptr;				//�ϵ������ ��� ���� ���˰� �ڿ� �Ҵ翡 ���Ǵ� �������̽�
	ID3D11DeviceContext* immediateContext = nullptr;	//���� ��� ���� �� �ڿ��� �׷��� ���������ο� ���ε��ϰ� GPU�� ������ ������ ��ɵ��� �����ϴ� ���� ���Ǵ� �������̽�
	IDXGISwapChain* dxgiSwapChain = nullptr;
	//�ؽ�ó�� PipeLine���κ��� View�� ���ؼ� Access�� ������, Render-Target�� �ؽ�ó�� �����̱� ������ ���� View�� �̿��Ͽ� Access�ؾ� �Ѵ�
	ID3D11RenderTargetView* renderTargetView = nullptr;	//Render-Target-View
	ID3D11Buffer* vertexBuffer;

public:
	CBaseDeviceManager();
	virtual ~CBaseDeviceManager();
};

