#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "res_path.h"
#include "timeController.h"

using namespace std;

class Player
{
public:

	/*static const int DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT, DIR_NONE;*/

	float playerX = 1;
	float playerY = 1;
	const float moveSpeed = 200;
	bool Movable = true;
	float MoveAmount = 0;

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	int tileX = 300, tileY = 100;
	int tileSize = 50;

	SDL_Renderer* renderer;
	SDL_Texture * player;

	SDL_Scancode UP, DOWN, LEFT, RIGHT;

	Player(SDL_Renderer* renderer);
	~Player();

	void update(SDL_Event& e);

	void draw();
	void Move(SDL_Event& e);
	void CheckForBoundary();

};

