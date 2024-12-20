#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Window.h"
#include "../Core/App.h"

class CirclePhysics;

class WindowSDL : public Window
{
public:
	WindowSDL(std::string winName, int SizeX, int SizeY, int fps);
	int Init(GameModeType* gameModeType) override;
	int Open() override;
	int IsOpen() override;
	int Clear() override;
	int Draw() override;
	int Update() override; 
	//int MakeSprite(std::string imgPath, int SizeX, int SizeY, Position pos) override;
	void DrawFps();
	SDL_Window* GetSDLWindow();
	SDL_Renderer* GetSDLRenderer();
private:
	SDL_Surface* m_winSurface = NULL;
	SDL_Window* m_window = NULL;
	GameMode* m_gamemode = NULL;
	SDL_Renderer* m_renderer = NULL;
	App m_app;
	int fps, desireDelta, Loop, frame;
};

