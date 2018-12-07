#include "Snow.h"

Snow::Snow()
{
	position = {1, -1};
	velocity = (GetRandomValue(50, 75))*.01;
}


Snow::~Snow()
{
}

void Snow::draw()
{
	if (!isFree && position.y > 0) {
		DrawRectangleV(position, { 2,2 }, WHITE);
		//DrawPixelV(position, WHITE);
	}
		
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

Vector2 Snow::getPos() {
	return position;
}

void Snow::setVel(float _velocity) {
	velocity = _velocity;
}

float Snow::getVel() {
	return velocity;
}

bool Snow::shouldStop(int height) {
	if (velocity > 0.00f) {
		if (position.y >= height) {
			return true;
		}
	}
	return false;
}