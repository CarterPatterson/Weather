#pragma once
#include "Terrain.h"
class tSnow : public Terrain
{
public:
	tSnow();
	tSnow(Vector2 _position);
	~tSnow();
	void Terrain::draw();
};

