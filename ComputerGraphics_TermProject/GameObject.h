#pragma once
#include "Transform.h"
#include "Colider.h"
#include "Rendering.h"
#include "Physics.h"
#include <vector>

class CGameObject : IUpdate
{
public:
	// IUpdate을(를) 통해 상속됨
	virtual void Update() override;
	void AddComponent(IUpdate* component);
	template <typename T>
	T* GetComponent();
private:
	CTransform transform;
	//CColider* colider = nullptr;
	//CRendering* rendering = nullptr;
	//CPhysics* physics = nullptr;
	std::vector<IUpdate*> updateList;

public:
	CGameObject();
	~CGameObject();
};

template<typename T>
inline T* CGameObject::GetComponent()
{
	for (IUpdate* item : updateList) {
		T* t = dynamic_cast<T*>(item);
		if (t)
			return t;
	}
	return nullptr;
}
