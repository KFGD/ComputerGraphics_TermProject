#pragma once
#include "Utility.h"

class CRendering : public IUpdate
{
public:
	CRendering();
	~CRendering();

	// IUpdate��(��) ���� ��ӵ�
	virtual void Update() override;
};

