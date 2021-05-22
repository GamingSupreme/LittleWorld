#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "res_path.h"

using namespace std;

class TimeController
{
public:
	static const int PLAY_STATE, PAUSE_STATE;

	int timeState;
	Uint32 lastUpdate;
	float DeltaTime;

	TimeController();
	void updateTime();
	void pause();
	void resume();
	void reset(); //MATTS NOTE //delta time, in seconds (1= 1 second, 0.5 is half a second). Time since the last frame was rendered onto screen

	static TimeController timeController;
};
