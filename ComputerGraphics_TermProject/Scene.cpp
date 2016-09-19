#include "Scene.h"



void CScene::SetUp(ID3D11DeviceContext * immediateContext, IDXGISwapChain * dxgiSwapChain, ID3D11RenderTargetView * renderTargerView)
{
	this->immediateContext = immediateContext;
	this->dxgiSwapChain = dxgiSwapChain;
	this->renderTargetView = renderTargerView;
}

void CScene::Awake()
{
}

void CScene::Start()
{
}

void CScene::Update()
{
	//float clearColor[] = { 1, 0, 1, 1 };			//보라색
	float clearColor[] = { 101 / 255.0f, 156 / 255.0f, 239 / 255.0f, 1 };	//하늘색

	immediateContext->ClearRenderTargetView(renderTargetView, clearColor);	//Render-Target을 clearColor색으로 지움

	//for (CGameObject* object : objectList)
	//	object->PhysicsUpdate();
	//for (CGameObject* object : objectList)
	//	object->RenderingUpdate(immediateContext);
	this->dxgiSwapChain->Present(0, 0);
}

CScene::CScene()
{
}


CScene::~CScene()
{
	for (CGameObject* object : objectList)
		delete object;
}
