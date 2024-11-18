#pragma once
#include <string>

enum Library 
{
	SDL,
	RAYLIB
};

//class WindowSDL;
//class WindowRayLib;

class Window
{
public:
	Window(std::string winName, int SizeX, int SizeY, Library lib);
	virtual int Init();
	virtual int Open(std::string winName, int SizeX, int SizeY);
	virtual int IsOpen();
	virtual int Clear();
	virtual int Draw();
private:
	Window MakeSDLWindow(std::string winName, int SizeX, int SizeY);
	Window MakeRayLibWindow(std::string winName, int SizeX, int SizeY);
};

