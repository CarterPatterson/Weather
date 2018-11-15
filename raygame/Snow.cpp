#include "Snow.h"

Snow::Snow()
{
	velocity = (GetRandomValue(50, 75))*.01;
}


Snow::~Snow()
{
}

void Snow::draw()
{
	if(!isFree)
		DrawRectangleV(position, {3,3}, WHITE);
}

void Snow::fall()
{
	if(!isFree)
		position.y += velocity;
}

void Snow::setPos(Vector2 _position)
{
	position = _position;
}

Terrain * Snow::transform()
{
	if (position.y >= GetScreenHeight()) {
		Terrain *t = new tSnow(position);
		return t;
	}
}