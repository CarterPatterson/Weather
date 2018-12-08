#include "Sun.h"

Sun::Sun()
{
	intensity = 1.0f;
	axis = {(float)(GetScreenWidth()/2), (float)(GetScreenHeight())};
	distance = (float)GetScreenHeight()*0.9;
	position = {axis.x, axis.y - distance};
	speed = 0.005f;
	deg = 180.0f;
}


Sun::~Sun()
{
}

void Sun::setPosition(Vector2 _position)
{
	position = _position;
}

Vector2 Sun::getPosition()
{
	return position;
}

void Sun::setIntensity(float _intensity)
{
	intensity = _intensity;
}

void Sun::setDeg(float _deg)
{
	deg = _deg;
}

float Sun::getIntensity()
{
	return intensity;
}

float Sun::getDeg()
{
	return deg;
}

void Sun::orbit()
{
	deg += speed;
	if (deg >= 360.0f)
		deg = 0.0f;
	phase = deg * PI /180;
	intensity = (-sin(phase) + 1) / 2;
	//std::cout << intensity << std::endl;
	std::cout << deg << "          " << phase << std::endl;
	position = {(float)cos(phase) * distance + axis.x, (float)sin(phase) * distance + axis.y};
}

void Sun::draw() {
	DrawCircleV(position, 60, {227, 112, 29, 150});
	DrawCircleV(position, 45, {230, 188, 82, 200});
	DrawCircleV(position, 30, YELLOW);
}
