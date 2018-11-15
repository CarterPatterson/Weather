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

#define SKYGREY  CLITERAL{ 147, 153, 165, 255 }   // Sky Grey
#define CURRENT_WEATHER_COLOR SKYGREY

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1000;
	int screenHeight = 600;

	const unsigned int TEMPMAX = 5000;
	Particle *snow = new Snow[TEMPMAX];
	std::vector <Terrain*> terrain;

	for (unsigned int i = 0; i < TEMPMAX; i++) {
		snow[i].setPos({ (float)(GetRandomValue(0, screenWidth)), (float)(GetRandomValue(-1500, -1)) });
	}

	InitWindow(screenWidth, screenHeight, "raylib [core] - Weather System");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		for (unsigned int i = 0; i < TEMPMAX; i++) {
			snow[i].fall();
			terrain.push_back(snow[i].transform());
		}

		std::cout << "ITERATE\n";
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(CURRENT_WEATHER_COLOR);

		for (unsigned int i = 0; i < TEMPMAX; i++) {
			snow[i].draw();
		}

		for (unsigned int i = 0; i < terrain.size(); i++) {
			terrain.at(i)->draw();
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}