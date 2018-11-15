#include "tSnow.h"



tSnow::tSnow()
{
}

tSnow::tSnow(Vector2 _position)
{
	position = _position;
}


tSnow::~tSnow()
{
}

void tSnow::draw() {
	DrawRectangleV(position, { 3,3 }, WHITE);
}