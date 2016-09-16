#pragma once
#include "Utility.h"

class CPhysics : public IUpdate
{
public:
	CPhysics();
	~CPhysics();

	// IUpdate을(를) 통해 상속됨
	virtual void Update() override;
};

