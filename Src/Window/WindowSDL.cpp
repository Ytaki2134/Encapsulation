#include "WindowSDL.h"
#include "../../Src/Physics/CirclePhysics.h"

WindowSDL::WindowSDL(std::string winName, int SizeX, int SizeY, int newfps)
{
	m_winName = winName;
	m_sizeX = SizeX;
	m_sizeY = SizeY;
	fps = newfps;
}

int WindowSDL::Init(GameModeType* gameModeType)
{
	m_app = App();

	//initialize desireDelta
	desireDelta = 1000 / fps;
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

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	if (!m_renderer)
	{
		std::cout << "Error getting renderer: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return 1;
	}

	m_circlePhysics = new CirclePhysics();
	m_circlePhysics->SetWindow(m_window);
	m_gamemode = GameMode::MakeGameMode(*gameModeType);
	if (m_gamemode != nullptr)
	{
		m_gamemode->Init(m_circlePhysics);
		for (Circle& circle : *m_circlePhysics->GetCirleList())
		{
			m_circlePhysics->MakeSpriteSDL(&circle);
		}
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
	Loop = SDL_GetTicks();

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
	//SDL_FillRect(m_winSurface, NULL, SDL_MapRGB(m_winSurface->format, 255, 255, 255));
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);

	//DRAW HERE
	for (Circle& circle : *m_circlePhysics->GetCirleList())
	{
		circle.sprite->LoadSprite();
	}

	this->DrawFps();
	// Update the window display
	SDL_RenderPresent(m_renderer);


	//SDL_UpdateWindowSurface(m_window);
	return 0;
}

int WindowSDL::Update()
{
	//m_gamemode->Update();
	m_app.EventLoop();
	for (auto& circle : *m_circlePhysics->GetCirleList())
	{
		circle.sprite->Update();
	}
	return 0;
}

//int WindowSDL::MakeSprite(std::string imgPath, int SizeX, int SizeY, Position pos)
//{
//	m_gamemode->AddSprite(Sprite::MakeSpriteSDL("Src/Ressources/masterBall.bmp", SizeX, SizeY, pos, m_window));
//	if (m_gamemode != nullptr)
//	{
//		return 0;
//	}
//	else
//	{
//		std::cout << "Error creating sprite in scene: " << SDL_GetError() << std::endl;
//		system("pause");
//		// End the program
//		return 1;
//	}
//}

void WindowSDL::DrawFps()
{
	int end = SDL_GetTicks() - Loop;
	if (end < desireDelta) {
		SDL_Delay(desireDelta-end);
		end = SDL_GetTicks() - Loop;
	}


	TTF_Init();
	TTF_Font* font = NULL;
	font = TTF_OpenFont("Src/Ressources/font/times.ttf", 20);
	
	if (font != NULL) {

		SDL_Rect postextfps;
		postextfps.x = 100;
		postextfps.y = 100;
		SDL_Color noir = { 0, 0, 0 }; 

		std::string txt = std::to_string( fps*((end/desireDelta)) );
		txt = "FPS: " + txt ;
		
		SDL_Surface* text;
		// Set color to black
		SDL_Color color = { 0, 0, 0 };

		text = TTF_RenderText_Solid(font, txt.c_str(), color);
		SDL_Texture* text_texture;
		text_texture = SDL_CreateTextureFromSurface(m_renderer, text);

		SDL_Rect dest = { 0, 0, text->w, text->h };
		SDL_RenderCopy(m_renderer,text_texture,NULL, &dest);


		//SDL_RenderCopy(texte, NULL, m_winSurface, NULL);
		SDL_FreeSurface(text); 
		TTF_CloseFont(font);
	}
	else { std::cout << "foirage à l'ouverture de times.ttf" << std::endl; }

	TTF_Quit();

}

SDL_Window* WindowSDL::GetSDLWindow()
{
	return m_window;
}

SDL_Renderer* WindowSDL::GetSDLRenderer()
{
	return m_renderer;
}
