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
		//todo
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

int Window::Open()
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
	return WindowSDL(winName, SizeX, SizeY);
}

Window Window::MakeRayLibWindow(std::string winName, int SizeX, int SizeY)
{
	//todo
	return WindowRayLib(winName, SizeX, SizeY);
}
