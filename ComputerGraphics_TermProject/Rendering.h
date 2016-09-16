#pragma once
#include "Utility.h"

class CRendering : public IUpdate
{
public:
	void SetVertexShaderDataFromFile(const char* fileName);
	void SetPixelShaderDataFromFile(const char* fileName);
private:
	void* vertexShaderData = nullptr;
	int vertexShaderLength;
	void* pixelShaderData = nullptr;
	int pixelShaderLength;

public:
	CRendering();
	~CRendering();

	// IUpdate을(를) 통해 상속됨
	virtual void Update() override;
};

