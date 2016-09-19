#include "BaseDeviceManager.h"


bool CBaseDeviceManager::InitializeDirect3D(HWND hWnd)
{
	if(CreateDeviceAndSwapChain(hWnd))
		return false;
	if (CreateRenderTargetView())
		return false;

	return true;
}

void CBaseDeviceManager::UninitializeDirect3D()
{
	if (nullptr != renderTargetView)
		renderTargetView->Release();
	if (nullptr != dxgiSwapChain)
		dxgiSwapChain->Release();
	if (nullptr != immediateContext)
		d3dDevice->Release();
	if (nullptr != d3dDevice)
		d3dDevice->Release();
}

CBaseDeviceManager::CBaseDeviceManager()
{
}


CBaseDeviceManager::~CBaseDeviceManager()
{
}


//Private Function

//InitializeDirect3D
bool CBaseDeviceManager::CreateDeviceAndSwapChain(HWND hWnd)
{
	DXGI_SWAP_CHAIN_DESC swapChainDesc = { 0, };		//교환 사슬의 특성들을 설정하기 위한 구조체
	swapChainDesc.BufferCount = 1;						//후면 버퍼의 개수: 1개
	swapChainDesc.BufferDesc = { 1280, 720,{ 60, 1 }, DXGI_FORMAT_R8G8B8A8_UNORM,
		DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED, DXGI_MODE_SCALING_STRETCHED };		//후면 버퍼의 속성들을 서술하는 개별적인 구조체(버퍼의 너비와 높이, 픽셀 형식 등)
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;				//후면 버퍼의 용도를 서술하는 구조체
	swapChainDesc.OutputWindow = hWnd;											//렌더링 결과를 표시할 창의 핸들
	swapChainDesc.SampleDesc = { 1, 0 };										//다중표본화를 위해 추출한 표본 개수와 품질 수준을 서술하는 구조체
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;						//사슬 교환 효과를 서술하는 구조체(DXGI_SWAP_EFFECT_DISCARD로 설정하면 디스플레이 구동기가 제시하는 가장 효율적인 방법을 설택)
	swapChainDesc.Windowed = true;												//창모드를 원하면 true, 전체화면을 원하면 false

	return FAILED(D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
		nullptr, 0, D3D11_SDK_VERSION, &swapChainDesc, &dxgiSwapChain, &d3dDevice,
		nullptr, &immediateContext));
}

bool CBaseDeviceManager::CreateRenderTargetView()
{
	D3D11_RENDER_TARGET_VIEW_DESC renderTargetViewDesc = {};	//사용하는데 없음, 렌더대상으로 사용할 자원(후면 버퍼)에 담긴 원소들의 자료 형식을 서술
																//렌더 대상 뷰를 생성하는 메소드(1: 렌더 대상으로 사용할 자원, 2: D3D11_RENDER_TARGET_VIEW_DESC 구조체 혹은 무형식이 아닐경우 nullptr, 3: 생성된 렌더 대상 뷰를 할당할 Render-Target-View의 포인터)
																//어떤 용도이든 Direct3D에서 텍스처를 사용하려면 텍스처의 초기화 시점에서 그 텍스처의 자원뷰를 생성해야 한다.
	ID3D11Resource* backBuffer;
	//SwapChanin으로부터 Back-Buffer의 포인터 획득(1: 후면 버퍼의 색인, 2: 버퍼의 인터페이스 형식을 지정, 3: 후면 버퍼를 가리키는 포인터)
	dxgiSwapChain->GetBuffer(0, __uuidof(ID3D11Resource), (void**)&backBuffer);

	bool bReturn = FAILED(d3dDevice->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView));

	backBuffer->Release();	//렌더 대상 뷰를 생성하였음으로 backBuffer를 해제

	return bReturn;
}

bool CBaseDeviceManager::CreateDepthStencilBufferAndBuffer()
{
	return true;
}

void CBaseDeviceManager::SetRenderTargets()
{
	immediateContext->OMSetRenderTargets(1, &renderTargetView, nullptr);	//OM Stage때, 하나 이상의 Render-Target과 깊이 혹은 스텐실 버퍼를 바인딩함(1: view의 개수, 2:장치에 바인딩하기 위한 Render-Target을 가리키는 ID3D11RenderTargetView Array Pointer)
}

void CBaseDeviceManager::SetViewports()
{
	//ViewPort 구조체
	D3D11_VIEWPORT viewport = { 0, };
	viewport.Width = 1280;
	viewport.Height = 720;
	viewport.MaxDepth = 1.0f;
	immediateContext->RSSetViewports(1, &viewport);	//Array of Viewports을 PipeLine의 Raterize-Stage에 바인딩하도록 명령
}

//UninitializeDirect3D
