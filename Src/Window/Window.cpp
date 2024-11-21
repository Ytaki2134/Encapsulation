#include "Window.h"
#include "WindowSDL.h"
#include "WindowRayLib.h"

Window* Window::MakeWindow(std::string winName, int SizeX, int SizeY, Library lib,int newfps)
{
	switch (lib)
	{
	case SDL:
		return MakeSDLWindow(winName, SizeX, SizeY, newfps);
		break;

	case RAYLIB:
		return MakeRayLibWindow(winName, SizeX, SizeY, newfps);
		break;

	default:
		//todo
		break;
	}
	return nullptr;
}

Window* Window::MakeSDLWindow(std::string winName, int SizeX, int SizeY,int fps)
{
	Window* win = new WindowSDL(winName, SizeX, SizeY,fps);
	return win;
}

Window* Window::MakeRayLibWindow(std::string winName, int SizeX, int SizeY, int fps)
{
	Window* win = new WindowRayLib(winName, SizeX, SizeY,fps);
	return win;
}
