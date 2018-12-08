/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Snow.h"
#include "Sun.h"
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#include <string>
#include <algorithm>

#define SKYGREY  CLITERAL{ 147, 153, 165, 255 }   // Sky Grey
#define CURRENT_WEATHER_COLOR SKYGREY

Color randColor() { //Select random color from given list
	Color c;

	int r = GetRandomValue(0, 20);

	switch (r) {
	case 0:
		c = LIGHTGRAY;
		break;
	case 1:
		c = GRAY;
		break;
	case 2:
		c = DARKGRAY;
		break;
	case 3:
		c = YELLOW;
		break;
	case 4:
		c = GOLD;
		break;
	case 5:
		c = ORANGE;
		break;
	case 6:
		c = PINK;
		break;
	case 7:
		c = RED;
		break;
	case 8:
		c = MAROON;
		break;
	case 9:
		c = GREEN;
		break;
	case 10:
		c = LIME;
		break;
	case 11:
		c = DARKGREEN;
		break;
	case 12:
		c = SKYBLUE;
		break;
	case 13:
		c = BLUE;
		break;
	case 14:
		c = DARKBLUE;
		break;
	case 15:
		c = PURPLE;
		break;
	case 16:
		c = VIOLET;
		break;
	case 17:
		c = DARKPURPLE;
		break;
	case 18:
		c = BEIGE;
		break;
	case 19:
		c = BROWN;
		break;
	case 20:
		c = DARKBROWN;
		break;
	}
	return c;
}

float lerp(float start, float end, float percent, float maxChange) { //My linear interpolation function

	if ((end - start) * percent < maxChange) {
		start += percent * (end - start);
	} else {
		if (end - start >= 0) {
			start += maxChange;
		} else {
			start -= maxChange;
		}
	}

	return start;
}

void displace(size_t _i, int* _heightMap) {
	int range = 0;
	bool shouldDisplace = false;

	for (int j = -1; j < 2; j++) {
		if (_heightMap[_i + j] - _heightMap[_i] > 2) {
			shouldDisplace = true;
			range += j;
		}
	}
	if (shouldDisplace) {
		if (range == 0) {
			_heightMap[_i] += 2;
			_heightMap[_i - 1]--;
			_heightMap[_i + 1]--;
		} else {
			_heightMap[_i]++;
			_heightMap[_i + range]--;
			if(_i + range != 0 || _i + range != GetScreenWidth() + 1)
			displace(_i + range, _heightMap);
		}
		displace(_i, _heightMap);
	}
}

void melt(int* _heightMap, int sT, Sun* _sun) {
	Vector2 sPos = _sun->getPosition();
	int w = GetScreenWidth();
	int h = GetScreenHeight();
	float intensity = _sun->getIntensity();


	if (sPos.x > 0 && sPos.x < w + 1) {
		if (sPos.y < h) {
			if (_heightMap[(int)sPos.x] < h) {
				
			}			
		}
	}
}

float changeTemp(float cTemp, Sun* _sun) {
	float in = _sun->getIntensity();
	float deg = _sun->getDeg();




	if (in > 0.7f && deg > 270 || in > 0.5f && deg <= 270) {
		cTemp = lerp(cTemp, 35, 0.1f, 0.01f);
	} else {
		cTemp = lerp(cTemp, -15, 0.1f, 0.01f);
	}
	return cTemp;
}


int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	srand(time(NULL));

	const int screenWidth = 1600;
	const int screenHeight = 800;

	const unsigned int TEMPMAX = 3000;

	std::vector <Particle*> particles(TEMPMAX);
	int heightMap[screenWidth + 2];

	
	for (size_t i = 0; i < screenWidth + 2; i++) {
		heightMap[i] = screenHeight - 1;
	}

	heightMap[0] = 0;
	heightMap[screenWidth + 1] = 0;

	for (unsigned int i = 0; i < TEMPMAX; i++) {
		particles[i] = new Snow;
		particles[i]->position = { (float)GetRandomValue(1, screenWidth), (float)GetRandomValue(-1500, -1) };
	}

	InitWindow(screenWidth, screenHeight, "raylib [core] - Weather System");

	Sun sun;
	Sun* sunP = &sun;

	float temperature = 0;

	SetTargetFPS(60*10);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------

		sun.orbit();
		
		temperature = changeTemp(temperature, sunP);
		//std::cout << temperature << std::endl;

		for (unsigned int i = 0; i < particles.size(); i++) {
			particles[i]->fall();
			int xIndex = (int)particles[i]->position.x;
			if (particles[i]->shouldStop(heightMap[xIndex])) {
				heightMap[xIndex]--;
				particles[i]->position = { (float)GetRandomValue(1, screenWidth), (float)GetRandomValue(-1500, -1) };
				}
			}

		//----------------------------------------------------------------------------------
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(CURRENT_WEATHER_COLOR);

		sun.draw();

		for (unsigned int i = 0; i < particles.size(); i++) {
			particles[i]->draw();
		}

		for (size_t i = 1; i < screenWidth; i++) {
			DrawRectangle(i, heightMap[i], 1, screenHeight - heightMap[i], WHITE);
			displace(i, heightMap);
			if(sun.getPosition().x > 0 || sun.getPosition().x < GetScreenWidth() + 1)
				melt(heightMap, temperature, sunP);
		}

		DrawFPS(100, 100);
		DrawText(std::to_string(temperature).c_str(), 100, 200, 50, BLACK);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}