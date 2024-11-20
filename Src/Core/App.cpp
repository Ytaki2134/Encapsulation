#include "App.h"

void App::EventLoop()
{
	SDL_Event event;

	while (m_isRunning && SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_USEREVENT:
			HandleUserEvents(&event);
			break;

		case SDL_KEYDOWN:
			// Handle any key presses here.
			break;

		case SDL_MOUSEBUTTONDOWN:
			// Handle mouse clicks here.
			break;

		case SDL_QUIT:
			m_isRunning = false;
			
			break;

		default:
			break;
		}   // End switch

	}   // End while
}

bool App::IsAppRunning()
{
	return m_isRunning;
}

void App::HandleUserEvents(SDL_Event* event)
{
	switch (event->user.code) {
	//case RUN_GAME_LOOP:
	//	GameLoop();
	//	break;

	default:
		break;
	}
}
