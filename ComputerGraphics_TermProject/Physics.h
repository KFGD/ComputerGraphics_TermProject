#pragma once
#include "Utility.h"

class CPhysics : public IUpdate
{
public:
	CPhysics();
	~CPhysics();

	// IUpdate��(��) ���� ��ӵ�
	virtual void Update() override;
};

