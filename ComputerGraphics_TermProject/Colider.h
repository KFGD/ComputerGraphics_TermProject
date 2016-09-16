#pragma once
#include "Utility.h"

class CColider : public IUpdate
{
public:
	// IUpdate을(를) 통해 상속됨
	virtual void Update() override;
	void OnTriggerEnter(CColider& colider);
	void OnTriggerExit(CColider& colider);
	void OnTriggerStay(CColider& colider);
private:
	bool isTrigger;
	Vector3 center;
	Vector3 size;
public:
	//Constructer / Destructors & Getter / Setter
	CColider();
	~CColider();
	void SetIsTrigger(bool isOn);
	void SetCenter(Vector3 center);
	void SetSize(Vector3 size);
	bool GetIsTrigger();
	Vector3 GetCenter();
	Vector3 GetSize();
};

