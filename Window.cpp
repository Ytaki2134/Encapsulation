#include "Window.h"
#include "WindowSDL.h"
#include "WindowRayLib.h"

Window* Window::MakeWindow(std::string winName, int SizeX, int SizeY, Library lib)
{
	switch (lib)
	{
	case SDL:
		return MakeSDLWindow(winName, SizeX, SizeY);
		break;

	case RAYLIB:
		//todo
		break;

	default:
		//todo
		break;
	}
	return nullptr;
}

Window* Window::MakeSDLWindow(std::string winName, int SizeX, int SizeY)
{
	Window* win = new WindowSDL(winName, SizeX, SizeY);
	return win;
}

Window* Window::MakeRayLibWindow(std::string winName, int SizeX, int SizeY)
{
	Window* win = new WindowRayLib(winName, SizeX, SizeY);
	return win;
}
