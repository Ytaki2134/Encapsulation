#pragma once
#include <string>
#include "../GameMode/GameMode.h"

enum Library 
{
	SDL,
	RAYLIB
};

class WindowSDL;
class WindowRayLib;

class Window
{
public:
	static Window* MakeWindow(std::string winName, int SizeX, int SizeY, Library lib, int fps);
	virtual int Init(GameModeType* gameModeType) = 0;
	virtual int Open() = 0;
	virtual int IsOpen() = 0;
	virtual int Clear() = 0;
	virtual int Draw() = 0;
	virtual int Update() = 0;
	virtual int MakeSprite(std::string imgPath, int SizeX, int SizeY, Position pos) = 0;
protected:
	std::string m_winName;
	int m_sizeX, m_sizeY;
	GameMode* m_gamemode = nullptr;
private:
	static Window* MakeSDLWindow(std::string winName, int SizeX, int SizeY, int fps);
	static Window* MakeRayLibWindow(std::string winName, int SizeX, int SizeY, int fps);
};

