#pragma once
#include <iostream>
#include <SDL.h>

#include "Window.h"

class WindowSDL : public Window
{
public:
	WindowSDL();
	int Init() ;
	int Open(std::string winName, int SizeX, int SizeY) ;
	int IsOpen() ;
	int Clear() ;
	int Draw() ;
private:
	SDL_Surface* winSurface = NULL;
	SDL_Window* window = NULL;
};

