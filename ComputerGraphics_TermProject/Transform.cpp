#include "Transform.h"

CTransform::CTransform()
{
}


CTransform::~CTransform()
{
}

// setter / getter : field
void CTransform::SetPosition(Vector3& position) { CTransform::position = position; }
void CTransform::SetRotation(Vector3& rotation) { CTransform::rotation = rotation; }
void CTransform::SetScale(Vector3& scale) { CTransform::scale = scale; }
Vector3 CTransform::GetPosition() { return CTransform::position; }
Vector3 CTransform::GetRotation() { return CTransform::rotation; }
Vector3 CTransform::GetScale() { return CTransform::scale; }