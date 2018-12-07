#pragma once
#include <vector>
#include <random>
#include "raylib.h"

class Particle {
public:
	virtual void draw() = 0;
	virtual void fall() = 0;
	virtual void setPos(Vector2 _position) = 0;
	virtual Vector2 getPos() = 0;
	virtual void setVel(float _velocity) = 0;
	virtual float getVel() = 0;
	virtual bool shouldStop(int height) = 0;

	Vector2 position;
protected:
	float velocity;
	bool isFree = false;
};