#include "Player.h"

Player::Player(SDL_Renderer* renderer)
{
	this->renderer = renderer;

	player = IMG_LoadTexture(renderer, "assets/Player.png");
}

Player::~Player()
{
	SDL_DestroyTexture(player);
}

void Player::draw()
{
	SDL_Rect drawRect;
	drawRect.x = tileX + (playerX);
	drawRect.y = tileY + (playerY);
	drawRect.w = tileSize;
	drawRect.h = tileSize;

	SDL_RenderCopy(renderer, player, NULL, &drawRect);
}

void Player::Move(SDL_Event& e)
{
	
		if (e.key.keysym.scancode == SDL_SCANCODE_D)
		{
			playerX++;
		}
		if (e.key.keysym.scancode == SDL_SCANCODE_A)
		{
			playerX--;
		}
		if (e.key.keysym.scancode == SDL_SCANCODE_W)
		{
			playerY--;
		}
		if (e.key.keysym.scancode == SDL_SCANCODE_S)
		{
			playerY++;
		}
	
}
