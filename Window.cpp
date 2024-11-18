#include "Window.h"

Window::Window(std::string winName, int SizeX, int SizeY, Library lib)
{
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

}

int Window::Open(std::string winName, int SizeX, int SizeY)
{
	return 0;
}


int Window::IsOpen()
{

}

int Window::Clear()
{

}

int Window::Draw()
{

}

Window Window::MakeSDLWindow(std::string winName, int SizeX, int SizeY)
{
	return WindowSDL();
}

Window Window::MakeRayLibWindow(std::string winName, int SizeX, int SizeY)
{
	return WindowRayLib();
}
