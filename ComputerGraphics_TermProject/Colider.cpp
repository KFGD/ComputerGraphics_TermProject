#include "Colider.h"



CColider::CColider()
{
}


CColider::~CColider()
{
}

//setter / getter : field
void CColider::SetIsTrigger(bool isOn) { CColider::isTrigger = isOn; }
void CColider::SetCenter(Vector3 center) { CColider::center = center; }
void CColider::SetSize(Vector3 size) { CColider::size = size; }
bool CColider::GetIsTrigger() { return CColider::isTrigger; }
Vector3 CColider::GetCenter() { return CColider::center; }
Vector3 CColider::GetSize() { return CColider::size; }

void CColider::Update()
{

}

void CColider::OnTriggerEnter(CColider& colider)
{
	
}

void CColider::OnTriggerExit(CColider& colider)
{

}

void CColider::OnTriggerStay(CColider& colider)
{

}
