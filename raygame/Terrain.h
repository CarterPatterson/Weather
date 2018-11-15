#pragma once
#include "raylib.h"

class Terrain {
public:
	virtual void draw() = 0;
protected:
	Vector2 position;
};