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
#include <vector>
#include <iostream>
#include <random>
#include <time.h>

#define SKYGREY  CLITERAL{ 147, 153, 165, 255 }   // Sky Grey
#define CURRENT_WEATHER_COLOR SKYGREY

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	srand(time(NULL));

	const int screenWidth = 1000;
	const int screenHeight = 600;

	const unsigned int TEMPMAX = 10000;
	std::vector <Particle*> particles(TEMPMAX);
	//int* heightMap = new int[screenWidth];
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

	SetTargetFPS(60*10);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		for (unsigned int i = 0; i < particles.size(); i++) {
			particles[i]->fall();
			int xIndex = (int)particles[i]->position.x;
			if (particles[i]->shouldStop(heightMap[xIndex])) {
				if (heightMap[xIndex - 1] > heightMap[xIndex]) {
					particles[i]->position.x--;
					for (size_t j = particles[i]->position.y; j < heightMap[xIndex - 1]; j++) {
						particles[i]->fall();
					}
					continue;
				} else if (heightMap[xIndex + 1] > heightMap[xIndex]) {
					particles[i]->position.x++;
					for (size_t j = particles[i]->position.y; j < heightMap[xIndex + 1]; j++) {
						particles[i]->fall();
					}
					continue;
				}
				particles[i]->setVel(0.0f);
				heightMap[xIndex]--;
				}
			}

		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(CURRENT_WEATHER_COLOR);

		for (unsigned int i = 0; i < particles.size(); i++) {
			particles[i]->draw();
		}

		DrawFPS(100, 100);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}