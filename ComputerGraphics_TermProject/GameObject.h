#pragma once
#include "Transform.h"
#include "Colider.h"
#include "Rendering.h"
#include "Physics.h"

class CGameObject
{
public:
	void PhysicsUpdate();
	void RenderingUpdate(ID3D11DeviceContext* immediateContext);

public:
	void AddComponent(CColider* colider);
	void AddComponent(CRendering* rendering);
	void AddComponent(CPhysics* physics);

	template <typename T> T* GetComponent();
	template <> CTransform* GetComponent<CTransform>();
	template <> CColider* GetComponent<CColider>();
	template <> CRendering* GetComponent<CRendering>();
	template <> CPhysics* GetComponent<CPhysics>();
	
	template <typename T> void RemoveComponent();
	template <> void RemoveComponent<CColider>();
	template <> void RemoveComponent<CRendering>();
	template <> void RemoveComponent<CPhysics>();

private:

private:
	CTransform transform;
	CColider* colider = nullptr;
	CRendering* rendering = nullptr;
	CPhysics* physics = nullptr;

public:
	CGameObject();
	virtual ~CGameObject();
};

template<typename T>
inline T* CGameObject::GetComponent()
{
	/*for (IUpdate* item : updateList) {
		T* t = dynamic_cast<T*>(item);
		if (t)
			return t;
	}*/
	return nullptr;
}

template<>
inline CTransform* CGameObject::GetComponent<CTransform>()
{
	return &(CGameObject::transform);
}

template<>
inline CColider* CGameObject::GetComponent<CColider>()
{
	return this->colider;
}

template<>
inline CRendering* CGameObject::GetComponent<CRendering>()
{
	return this->rendering;
}

template<>
inline CPhysics* CGameObject::GetComponent<CPhysics>()
{
	return this->physics;
}