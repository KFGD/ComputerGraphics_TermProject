#include "Rendering.h"



void CRendering::SetVertexShaderDataFromFile(const char * fileName)
{
	ReadData(fileName, (void**)&this->vertexShaderData, &this->vertexShaderLength);
}

void CRendering::SetPixelShaderDataFromFile(const char * fileName)
{
	ReadData(fileName, (void**)&this->pixelShaderData, &this-> pixelShaderLength);
}

CRendering::CRendering()
{
}


CRendering::~CRendering()
{
}

void CRendering::Update()
{
}
