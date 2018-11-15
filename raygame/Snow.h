#pragma once
#include "Particle.h"
#include "tSnow.h"
class Snow : public Particle
{
public:
	Snow();
	~Snow();
	void Particle::draw();
	void Particle::fall();
	void Particle::setPos(Vector2 _position);
	Terrain * Particle::transform();
};

