#pragma once
#include "World.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "res_path.h"

using namespace std;

class ResourceNode
{
public:

	//static char GRASS;
	//static char ROCK;
	//static char TREE;

	string type;
	int Xpos;
	int Ypos;


	ResourceNode(string type, int PosX, int PosY);


};

