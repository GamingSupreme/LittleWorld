#include "Player.h"

//const int Player::DIR_UP = 0, Player::DIR_DOWN = 1, Player::DIR_LEFT = 2, Player::DIR_RIGHT = 3, Player::DIR_NONE = -1;


Player::Player(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	/*UP = SDL_SCANCODE_UP;
	DOWN = SDL_SCANCODE_DOWN;
	LEFT = SDL_SCANCODE_LEFT;
	RIGHT = SDL_SCANCODE_RIGHT;*/

	player = IMG_LoadTexture(renderer, "assets/Player.png");
}

Player::~Player()
{
	SDL_DestroyTexture(player);
}

void Player::update(SDL_Event& e)
{
	draw();
	Move(e);
	CheckForBoundary();
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
	if (Movable == true)
	{
		if (keys[SDL_SCANCODE_D])//(e.key.keysym.scancode == SDL_SCANCODE_D)
		{
			MoveAmount = moveSpeed * TimeController::timeController.DeltaTime;
			playerX += MoveAmount;
		}
		if (keys[SDL_SCANCODE_A])//(e.key.keysym.scancode == SDL_SCANCODE_A)
		{
			MoveAmount = moveSpeed * TimeController::timeController.DeltaTime;
			playerX -= MoveAmount;
		}
		if (keys[SDL_SCANCODE_W])//(e.key.keysym.scancode == SDL_SCANCODE_W)
		{
			MoveAmount = moveSpeed * TimeController::timeController.DeltaTime;
			playerY -= MoveAmount;
		}
		if (keys[SDL_SCANCODE_S])//(e.key.keysym.scancode == SDL_SCANCODE_S)
		{
			MoveAmount = moveSpeed * TimeController::timeController.DeltaTime;
			playerY += MoveAmount;
		}
	}
}

void Player::CheckForBoundary()
{
	/*if ((playerX + tileX) < tileX || (playerX + tileX) > tileX + (tileSize * 9) || (playerY + tileY) < tileY || (playerY + tileY) > tileY + (tileSize * 9))
	{
		Movable = false;
		playerX + 10;
		playerY + 10;
	}
	else
		Movable = true;*/
	if (playerX < 0)
		playerX = 0;
	if (playerY < 0)
		playerY = 0;
	if (playerX > tileSize * 9)
		playerX = tileSize * 9;
	if (playerY > tileSize * 9)
		playerY = tileSize * 9;
}
