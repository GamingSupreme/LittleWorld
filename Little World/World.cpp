#include "World.h"
char World::GRASS = 'G';
char World::ROCK = 'R';
char World::TREE = 'T';

World::World(SDL_Renderer* renderer)
{
	this->renderer = renderer;

	grass = IMG_LoadTexture(renderer, "assets/GrassTile.png");
	tree = IMG_LoadTexture(renderer, "assets/TreeTile.png");
	rock = IMG_LoadTexture(renderer, "assets/RockTile.png");

	clearBoard();
}

World::~World()
{
	SDL_DestroyTexture(grass);
	SDL_DestroyTexture(rock);
	SDL_DestroyTexture(tree);
}

void World::clearBoard()
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			world[x][y] = GRASS;
		}
	}
}

int World::ResourseGen(string type, int PosX, int PosY)
{
	int returnValue =1;
	if (world[PosX][PosY] == GRASS)
	{
		if (type == "Rock" && world[PosX][PosY] != TREE)
		{
			char charType;
			SDL_Rect drawRect;
			drawRect.x = tileX + (PosX * tileSize);
			drawRect.y = tileY + (PosY * tileSize);
			drawRect.w = tileSize;
			drawRect.h = tileSize;
			charType = ROCK;

			world[PosX][PosY] = charType;

			SDL_RenderCopy(renderer, rock, NULL, &drawRect);
		}
		/*else
			returnValue = 0;*/
		if (type == "Tree" && world[PosX][PosY] != ROCK)
		{
			char charType;
			SDL_Rect drawRect;
			drawRect.x = tileX + (PosX * tileSize);
			drawRect.y = tileY + (PosY * tileSize);
			drawRect.w = tileSize;
			drawRect.h = tileSize;
			charType = TREE;

			world[PosX][PosY] = charType;

			SDL_RenderCopy(renderer, tree, NULL, &drawRect);
		}
		/*else
			returnValue = 0;*/
		if (type == "Tree" && world[PosX][PosY] == ROCK)
			returnValue = 0;
		if (type == "Rock" && world[PosX][PosY] == TREE)
			returnValue = 0;
	}
	else
		returnValue = 0;
	return returnValue;
}

void World::draw()
{
	SDL_Rect drawRect;
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			SDL_Rect drawRect;
			drawRect.x = tileX + (x * tileSize);
			drawRect.y = tileY + (y * tileSize);
			drawRect.w = tileSize;
			drawRect.h = tileSize;

			if (world[x][y] == GRASS)
				SDL_RenderCopy(renderer, grass, NULL, &drawRect);
			if (world[x][y] == ROCK)
				SDL_RenderCopy(renderer, rock, NULL, &drawRect);
			if (world[x][y] == TREE)
				SDL_RenderCopy(renderer, tree, NULL, &drawRect);
		}
	}
}

//void World::ChangeTileType(string type, int PosX, int PosY)
//{
//	if (type == "Rock")
//	{
//		world[PosX][PosY] = ROCK;
//	}
//	if (type == "Tree")
//	{
//		world[PosX][PosY] = TREE;
//	}
//}
