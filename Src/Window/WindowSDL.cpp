#include "WindowSDL.h"

WindowSDL::WindowSDL(std::string winName, int SizeX, int SizeY)
{
	m_winName = winName;
	m_sizeX = SizeX;
	m_sizeY = SizeY;
}

int WindowSDL::Init(GameModeType* gameModeType)
{
	m_app = App();

	// Initialize SDL. SDL_Init will return -1 if it fails.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}

	// Create our window
	m_window = SDL_CreateWindow(m_winName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_sizeX, m_sizeY, SDL_WINDOW_HIDDEN);

	// Make sure creating the window succeeded
	if (!m_window) {
		std::cout << "Error creating window: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}

	m_gamemode = GameMode::MakeGameMode(*gameModeType);
	if (m_gamemode != nullptr)
	{
		m_gamemode->Init(this);
		return 0;
	}
	else
	{
		std::cout << "Error Loading Gamemode: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}

}

int WindowSDL::Open()
{

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

	SDL_ShowWindow(m_window);
	return 0;
}

int WindowSDL::IsOpen()
{
	if (m_app.IsAppRunning())
		return 0;

	else
		return 1;
}

int WindowSDL::Clear()
{
	// Fill the window with a white rectangle
	SDL_FillRect(m_winSurface, NULL, SDL_MapRGB(m_winSurface->format, 255, 255, 255));
	if (SDL_RenderClear(m_renderer))
	{
		return 0;
	}
	else
		return 1;
}

int WindowSDL::Draw()
{
	// Fill the window with a white rectangle
	SDL_FillRect(m_winSurface, NULL, SDL_MapRGB(m_winSurface->format, 255, 255, 255));

	//DRAW HERE
	for (auto& sprite : m_gamemode->GetSpriteVector())
	{
		sprite->LoadSprite();
	}

	// Update the window display
	SDL_UpdateWindowSurface(m_window);

	return 0;
}

int WindowSDL::Update()
{
	m_app.EventLoop();
	return 0;
}

int WindowSDL::MakeSprite(std::string imgPath, int SizeX, int SizeY, Position pos)
{
	m_gamemode->AddSprite(Sprite::MakeSpriteSDL("Src/Ressources/masterBall.bmp", SizeX, SizeY, pos, m_window));
	if (m_gamemode != nullptr)
	{
		return 0;
	}
	else
	{
		std::cout << "Error creating sprite in scene: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}
}

SDL_Window* WindowSDL::GetSDLWindow()
{
	return m_window;
}

SDL_Renderer* WindowSDL::GetSDLRenderer()
{
	return m_renderer;
}
