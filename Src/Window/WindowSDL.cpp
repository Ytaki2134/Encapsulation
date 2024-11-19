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
	m_window = SDL_CreateWindow(m_winName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_sizeX, m_sizeY, SDL_WINDOW_SHOWN);

	// Make sure creating the window succeeded
	if (!m_window) {
		std::cout << "Error creating window: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}

	// Get the surface from the window
	m_winSurface = SDL_GetWindowSurface(m_window);

	// Make sure getting the surface succeeded
	if (!m_winSurface) {
		std::cout << "Error getting surface: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	if (!m_renderer)
	{
		std::cout << "Error getting renderer: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}

	return 0;
}

int WindowSDL::IsOpen()
{
	if (m_window != NULL)
		return 0;

	else
		return 1;
}

int WindowSDL::Clear()
{
	if (SDL_RenderClear(m_renderer))
		return 0;
	else
		return 1;
}

int WindowSDL::Draw()
{
	// Fill the window with a white rectangle
	SDL_FillRect(m_winSurface, NULL, SDL_MapRGB(m_winSurface->format, 255, 255, 255));

	//DRAW HERE
	//BOUNCING BALLS SCENE
	SDL_Surface* pSprite = SDL_LoadBMP("Src/Ressources/masterBall.bmp");
	if (pSprite)
	{
		SDL_Rect dest = { 640 / 2 - pSprite->w / 2,480 / 2 - pSprite->h / 2, 0, 0 };
		SDL_BlitSurface(pSprite, NULL, SDL_GetWindowSurface(m_window), &dest); // Copie du sprite

		SDL_UpdateWindowSurface(m_window); // Mise à jour de la fenêtre pour prendre en compte la copie du sprite
		SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

		SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
	}
	else
	{
		fprintf(stdout, "Échec de chargement du sprite (%s)\n", SDL_GetError());
	}

	// Update the window display
	SDL_UpdateWindowSurface(m_window);

	return 0;
}
