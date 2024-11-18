#pragma once
#include <string>

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
	Window();
	Window(std::string winName, int SizeX, int SizeY, Library lib);
	virtual int Init() = 0;
	virtual int Open() = 0;
	virtual int IsOpen() = 0;
	virtual int Clear() = 0;
	virtual int Draw() = 0;
protected:
	std::string m_winName;
	int m_sizeX, m_sizeY;
private:
	Window* MakeSDLWindow(std::string winName, int SizeX, int SizeY);
	Window* MakeRayLibWindow(std::string winName, int SizeX, int SizeY);
};

