#pragma once
#include <iostream>
#include <SDL.h>

class Window;

class WindowSDL : public Window
{
public:
	WindowSDL();
	int Init() override;
	int Open(std::string winName, int SizeX, int SizeY) override;
	int IsOpen() override;
	int Clear() override;
	int Draw() override;
private:
	SDL_Surface* winSurface = NULL;
	SDL_Window* window = NULL;
};

