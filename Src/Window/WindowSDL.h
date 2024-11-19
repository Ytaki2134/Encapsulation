#pragma once
#include <iostream>
#include <SDL.h>

#include "Window.h"

class WindowSDL : public Window
{
public:
	WindowSDL(std::string winName, int SizeX, int SizeY);
	int Init() override;
	int Open() override;
	int IsOpen() override;
	int Clear() override;
	int Draw() override;
private:
	SDL_Surface* m_winSurface = NULL;
	SDL_Window* m_window = NULL;
	SDL_Renderer* m_renderer = NULL;
};
