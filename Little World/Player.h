#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "res_path.h"

using namespace std;

class Player
{
public:

	int playerX = 0;
	int playerY = 0;
	int tileX = 300, tileY = 100;
	int tileSize = 50;

	SDL_Renderer* renderer;
	SDL_Texture * player;

	Player(SDL_Renderer* renderer);
	~Player();
	void draw();

	void Move(SDL_Event& e);

};

