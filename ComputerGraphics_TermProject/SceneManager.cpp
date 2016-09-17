#include "SceneManager.h"



CSceneManager::CSceneManager()
{
}


CSceneManager::~CSceneManager()
{
}

void CSceneManager::RenderSceneElements(ID3D11DeviceContext * immediateContext, IDXGISwapChain* dxgiSwapChain, ID3D11RenderTargetView* renderTargetView)
{
	//float clearColor[] = { 1, 0, 1, 1 };			//보라색
	float clearColor[] = { 101 / 255.0f, 156 / 255.0f, 239 / 255.0f, 1 };	//하늘색
	immediateContext->ClearRenderTargetView(renderTargetView, clearColor);	//Render-Target을 clearColor색으로 지움

	for (CGameObject* object : objectList)
		object->RenderingUpdate(immediateContext, );

	dxgiSwapChain->Present(0, 0);
}

void CSceneManager::UpdateSceneElements(ID3D11DeviceContext* immediataContext)
{
	for (CGameObject* object : objectList)
		object->PhysicsUpdate();
}
