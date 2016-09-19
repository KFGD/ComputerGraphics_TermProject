#pragma once
#include "Utility.h"
#include <d3d11.h>

class CRendering
{
public:
	void Update(ID3D11DeviceContext* immediateContext);
	void SetInputLayout(ID3D11InputLayout* inputLayout);
	void SetVertexShader(ID3D11VertexShader* vertexShader);
	void SetPixelShader(ID3D11PixelShader* pixelShader);
	void SetBindingBuffer(ID3D11Buffer* bindingBuffer);
	int GetVerticesNum();
	Vector3* GetVertices();

private:
	Vector3& vertices;
	D3D_PRIMITIVE_TOPOLOGY primitiveTopology;
	ID3D11InputLayout* inputLayout;
	ID3D11VertexShader* vertexShader;
	ID3D11PixelShader* pixelShader;
	ID3D11Buffer* bindingBuffer;

public:
	CRendering(Vector3& vertices, D3D_PRIMITIVE_TOPOLOGY primitiveTopology);
	~CRendering();

};

