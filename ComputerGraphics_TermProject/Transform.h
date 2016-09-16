#pragma once
#include "Utility.h"

class CTransform
{
private:
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

public:
	//Constructer / Destructors & Getter / Setter
	CTransform();
	~CTransform();
	void SetPosition(Vector3& position);
	void SetRotation(Vector3& rotation);
	void SetScale(Vector3& scale);
	Vector3 GetPosition();
	Vector3 GetRotation();
	Vector3 GetScale();
};

