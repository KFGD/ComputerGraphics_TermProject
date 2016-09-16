#pragma once
#include "Utility.h"

class CRendering : public IUpdate
{
public:
	CRendering();
	~CRendering();

	// IUpdate을(를) 통해 상속됨
	virtual void Update() override;
};

