#include "TimeController.h"

const int TimeController::PLAY_STATE = 0, TimeController::PAUSE_STATE = 1;

TimeController::TimeController()
{
	DeltaTime = 0;
	lastUpdate = 0;
	timeState = PLAY_STATE;
}

void TimeController::updateTime()
{
	if (timeState == PAUSE_STATE)
	{
		DeltaTime = 0;
	}
	else
	{
		Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
		DeltaTime = timeDiff / 1000.0;
	}
}

void TimeController::pause()
{
	timeState = PAUSE_STATE;
}

void TimeController::resume()
{
	timeState = PLAY_STATE;
}

void TimeController::reset()
{
	DeltaTime = 0;
	lastUpdate = SDL_GetTicks();
}

//builds a global timeController object for use anywhere
TimeController TimeController::timeController;
