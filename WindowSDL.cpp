#include "WindowSDL.h"

WindowSDL::WindowSDL(std::string winName, int SizeX, int SizeY)
{
	m_winName = winName;
	m_sizeX = SizeX;
	m_sizeY = SizeY;
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
	return 0;
}

int WindowSDL::Open()
{
	// Create our window
	window = SDL_CreateWindow(m_winName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_sizeX, m_sizeY, SDL_WINDOW_SHOWN);

	// Make sure creating the window succeeded
	if (!window) {
		std::cout << "Error creating window: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}

	// Get the surface from the window
	winSurface = SDL_GetWindowSurface(window);

	// Make sure getting the surface succeeded
	if (!winSurface) {
		std::cout << "Error getting surface: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}

	return 0;
}

int WindowSDL::IsOpen()
{
	if (window != NULL)
		return 0;

	else
		return 1;
}

int WindowSDL::Clear()
{
	if (SDL_RenderClear())
		return 0;
	else
		return 1;
}

int WindowSDL::Draw()
{
	// Fill the window with a white rectangle
	SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 255, 255, 255));

	//DRAW HERE

	// Update the window display
	SDL_UpdateWindowSurface(window);

	return 0;
}
