#pragma once
#include "raylib.h"
#include "Terrain.h"

class Particle {
public:
	virtual void draw() = 0;
	virtual void fall() = 0;
	virtual void setPos(Vector2 _position) = 0;
	virtual Terrain * transform() = 0;
protected:
	float velocity;
	Vector2 position;
	bool isFree = false;
};