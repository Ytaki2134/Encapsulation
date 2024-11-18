#pragma once
#include "SDL.h"

class App
{
private:
	void HandleUserEvents(SDL_Event* event);
public:
	void EventLoop();
	bool IsAppRunning();

private:
	bool m_isRunning = true;
};

