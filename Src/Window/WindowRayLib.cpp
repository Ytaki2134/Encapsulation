#include "WindowRayLib.h"

WindowRayLib::WindowRayLib(std::string winName, int SizeX, int SizeY)
{
	m_winName = winName;
	m_sizeX = SizeX;
	m_sizeY = SizeY;
}

int WindowRayLib::Init(GameModeType* gameModeType)
{
	m_gamemode = GameMode::MakeGameMode(*gameModeType);
	if (m_gamemode != nullptr)
		return 0;
	else
		return 1;
}

int WindowRayLib::Open()
{
	InitWindow(m_sizeX, m_sizeY, m_winName.c_str());
	SetTargetFPS(60);
	BeginDrawing();
	ClearBackground(WHITE);
	EndDrawing();
	m_gamemode->Init(this);
	return 0;
}

int WindowRayLib::IsOpen()
{
	if (!WindowShouldClose())
		return 0;
	else
		return 1;
}

int WindowRayLib::Clear()
{
	ClearBackground(WHITE);
	return 0;
}

int WindowRayLib::Draw()
{
	BeginDrawing();
	ClearBackground(WHITE);
	for (auto& sprite : m_gamemode->GetSpriteVector())
	{
		sprite->LoadSprite();
	}
	EndDrawing();
	return 0;
}

int WindowRayLib::Update()
{
	return 0;
}

int WindowRayLib::MakeSprite(std::string imgPath, int SizeX, int SizeY, Position pos)
{
	if (Sprite::MakeSpriteRayLib("Src/Ressources/masterBall.png", SizeX, SizeY, pos) != nullptr)
	{
		m_gamemode->AddSprite(Sprite::MakeSpriteRayLib("Src/Ressources/masterBall.png", SizeX, SizeY, pos));
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

void WindowRayLib::Update()
{
	/*
	for (auto& sprite : m_gamemode->GetSpriteVector())
	{
		
	}
	*/
	m_gamemode->Update();
}
