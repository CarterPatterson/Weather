#pragma once
#include "Particle.h"
class Snow : public Particle
{
public:
	Snow();
	~Snow();
	void Particle::draw();
	void Particle::fall();
	void Particle::setPos(Vector2 _position);
	Vector2 Particle::getPos();
	void Particle::setVel(float _velocity);
	float Particle::getVel();
	bool Particle::shouldStop(int height);
};

