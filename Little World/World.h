#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "res_path.h"

using namespace std;

class World
{
public:
	static char GRASS;
	static char ROCK;
	static char TREE;

	SDL_Renderer* renderer;
	SDL_Texture* grass, * tree, * rock;

	char world[10][10];
	int tileX = 300, tileY = 100;
	int tileSize = 50;

	string type;

	World(SDL_Renderer* renderer);
	~World();
	void clearBoard();
	int ResourseGen(string type, int PosX, int PosY);

	void draw();

};

