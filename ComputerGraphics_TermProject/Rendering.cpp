#include "Rendering.h"


void CRendering::Update(ID3D11DeviceContext * immediateContext, ID3D11Buffer* bindingBuffer)
{
	immediateContext->VSSetShader(vertexShader, nullptr, 0);
	immediateContext->PSSetShader(pixelShader, nullptr, 0);

	immediateContext->IASetPrimitiveTopology(primitiveTopology);
	immediateContext->IASetInputLayout(inputLayout);
	UINT stride = sizeof(Vector3), offset = 0;
	immediateContext->IASetVertexBuffers(0, 1, &bindingBuffer, &stride, &offset);

	immediateContext->Draw(sizeof(vertices) / sizeof(Vector3), 0);
}

void CRendering::SetInputLayout(ID3D11InputLayout * inputLayout)
{
	this->inputLayout = inputLayout;
}

void CRendering::SetVertexShader(ID3D11VertexShader * vertexShader)
{
	this->vertexShader = vertexShader;
}

void CRendering::SetPixelShader(ID3D11PixelShader * pixelShader)
{
	this->pixelShader = pixelShader;
}

CRendering::CRendering(Vector3& vertices, D3D_PRIMITIVE_TOPOLOGY primitiveTopology)
{
	this->vertices = &vertices;
	this->primitiveTopology = primitiveTopology;
}


CRendering::~CRendering()
{
}
