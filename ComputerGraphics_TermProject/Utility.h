#pragma once

struct Vector3 { float x, y, z; };

class IUpdate {
public:
	virtual void Update() = 0;
};
