#pragma once
#include "raylib.h"
#include <math.h>
#include <iostream>
class Sun
{
private:
	Vector2 position;
	Vector2 axis;
	float distance;
	float intensity;
	float speed;
	float phase;
	float deg;

public:
	Sun();
	~Sun();

	void setPosition(Vector2 _position);
	void setIntensity(float _intensity);
	void setDeg(float _deg);

	Vector2 getPosition();
	float getIntensity();
	float getDeg();

	void orbit();
	void draw();
};