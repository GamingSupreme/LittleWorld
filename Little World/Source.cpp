#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <vector>
#include <SDL_ttf.h>
#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "World.h"
#include "ResourceNode.h"

using namespace std;

int randInRange(int rangeMax);
//void GenerateTile(string type, int PosX, int PosY, vector<ResourceNode> Nodes, World MainWorld);

int main(int argc, char** arrgv)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "Error: " << SDL_GetError() << endl;
		system("pause");
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Little World", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		cout << "Error: " << SDL_GetError() << endl;
		SDL_Quit();
		system("pause");
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL)
	{
		cout << "Error: " << SDL_GetError() << endl;
		SDL_DestroyWindow(window);
		system("pause");
		return 1;
	}

	TTF_Init();

	if (TTF_Init() != 0)
	{
		SDL_Quit();
		cout << "sdl ttf did not initialise" << endl;
		return 1;
	}
	
	int gameState = 1;
	World MainWorld(renderer);
	Player MainHero(renderer);
	int RocksSpawned = 0;
	int TreesSpawned = 0;
	bool quit = false;
	int RespawnDelay = 0;
	vector<ResourceNode> ResourceNodes;
	int seed = time(NULL);
	srand(seed);

	//MainWorld.draw();

	//game loop
	while (!quit)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			//user clicks close button
			if (e.type == SDL_QUIT)
				quit = true;
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				{
					quit = true;
				}

			}
		}
		MainHero.Move(e);
		
		
		SDL_SetRenderDrawColor(renderer, 170, 170, 170, 255); //rgba(0-255) //Use paint to change color of background, the first three numbers colorate to red green and blue
		SDL_RenderClear(renderer);

		MainWorld.draw();
		if (RespawnDelay == 50)
		{
			if (RocksSpawned < 10)
			{
				int spawned;
				spawned = MainWorld.ResourseGen("Rock", randInRange(9), randInRange(9));
				if (spawned == 1)
					RocksSpawned++;
				RespawnDelay = 0;
			}
			if (TreesSpawned < 10)
			{
				int spawned;
				spawned = MainWorld.ResourseGen("Tree", randInRange(9), randInRange(9));
				if (spawned == 1)
					TreesSpawned++;
				RespawnDelay = 0;
			}

		}
		//GenerateTile("Rock", 1, 1, ResourceNodes, MainWorld);
		MainHero.draw();
		

		SDL_RenderPresent(renderer);
		RespawnDelay++;
	}


	return 0;
}

int randInRange(int rangeMax)
{
	int rawRandom = rand();

	int ranged = rand() % (rangeMax + 1);

	return ranged;
}

//void GenerateTile(string type, int PosX, int PosY, vector<ResourceNode> Nodes, World TheWORLD)
//{
//	TheWORLD.ResourseGen(type, PosX, PosY);
//	Nodes.push_back(ResourceNode(type, PosX,PosY));
//
//}

