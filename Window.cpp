#include "Window.h"
#include "WindowSDL.h"
#include "WindowRayLib.h"

Window::Window()
{
}

Window::Window(std::string winName, int SizeX, int SizeY, Library lib)
{
	m_winName = "";
	m_sizeX = 0;
	m_sizeY = 0;

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
