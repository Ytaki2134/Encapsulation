#include "Window.h"
#include "WindowSDL.h"
#include "WindowRayLib.h"

Window::Window(std::string winName, int SizeX, int SizeY, Library lib)
{
	switch (lib)
	{
	case SDL:
		MakeSDLWindow(winName, SizeX, SizeY);
		break;

	case RAYLIB:
		MakeRayLibWindow(winName, SizeX, SizeY);
		break;

	default:
		//todo
		break;
	}
}

int Window::Init()
{
	return 0;
}

int Window::Open(std::string winName, int SizeX, int SizeY)
{
	return 0;
}


int Window::IsOpen()
{
	return 0;
}

int Window::Clear()
{
	return 0;
}

int Window::Draw()
{
	return 0;
}

Window Window::MakeSDLWindow(std::string winName, int SizeX, int SizeY)
{
	return WindowSDL();
}

Window Window::MakeRayLibWindow(std::string winName, int SizeX, int SizeY)
{
	return WindowRayLib();
}
