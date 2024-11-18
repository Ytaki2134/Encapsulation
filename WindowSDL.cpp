#include "WindowSDL.h"
#include "Window.h"

WindowSDL::WindowSDL()
{

}

int WindowSDL::Init()
{
	// Initialize SDL. SDL_Init will return -1 if it fails.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}
}

int WindowSDL::Open(std::string winName, int SizeX, int SizeY)
{
	// Create our window
	window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

	// Make sure creating the window succeeded
	if (!window) {
		std::cout << "Error creating window: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}
}

int WindowSDL::IsOpen()
{

}

int WindowSDL::Clear()
{

}

int WindowSDL::Draw()
{

}
