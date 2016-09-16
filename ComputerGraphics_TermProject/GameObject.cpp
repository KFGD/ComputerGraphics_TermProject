#include "GameObject.h"


CGameObject::CGameObject()
{
}

CGameObject::~CGameObject()
{
}

void CGameObject::Update()
{
	for (IUpdate* item : updateList)
		item->Update();
}

void CGameObject::AddComponent(IUpdate* component)
{
	updateList.push_back(component);
}