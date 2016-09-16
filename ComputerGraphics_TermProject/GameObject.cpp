#include "GameObject.h"


CGameObject::CGameObject()
{
}

CGameObject::~CGameObject()
{
	if (this->colider != nullptr)
		delete this->colider;
	if (this->physics != nullptr)
		delete this->physics;
	if (this->rendering != nullptr)
		delete this->rendering;
}

void CGameObject::PhysicsUpdate()
{
	if (physics != nullptr)
		physics->Update();
	if (colider != nullptr)
		colider->Update();
}

void CGameObject::RenderingUpdate()
{
	if (rendering != nullptr)
		rendering->Update();
}

void CGameObject::AddComponent(CColider * colider)
{
	if (this->colider != nullptr)
		delete this->colider;
	this->colider = colider;
}

void CGameObject::AddComponent(CRendering * rendering)
{
	if (this->rendering != nullptr)
		delete this->rendering;
	this->rendering = rendering;
}

void CGameObject::AddComponent(CPhysics * physics)
{
	if (this->physics != nullptr)
		delete this->physics;
	this->physics = physics;
}
