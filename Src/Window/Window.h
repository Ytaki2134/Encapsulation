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
	/*Window();
	Window(std::string winName, int SizeX, int SizeY, Library lib);*/
	static Window* MakeWindow(std::string winName, int SizeX, int SizeY, Library lib);
	virtual int Init() = 0;
	virtual int Open() = 0;
	virtual int IsOpen() = 0;
	virtual int Clear() = 0;
	virtual int Draw() = 0;
protected:
	std::string m_winName;
	int m_sizeX, m_sizeY;
	GameMode* m_gamemode = nullptr;
private:
	static Window* MakeSDLWindow(std::string winName, int SizeX, int SizeY);
	static Window* MakeRayLibWindow(std::string winName, int SizeX, int SizeY);
};

