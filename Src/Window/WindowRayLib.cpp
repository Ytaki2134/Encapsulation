#include "WindowRayLib.h"
#include "../../Src/Physics/CirclePhysics.h"

WindowRayLib::WindowRayLib(std::string winName, int SizeX, int SizeY,int newfps)
{
	m_winName = winName;
	m_sizeX = SizeX;
	m_sizeY = SizeY;
	fps = newfps;
}

int WindowRayLib::Init(GameModeType* gameModeType)
{
	m_circlePhysics = new CirclePhysics();
	m_gamemode = GameMode::MakeGameMode(*gameModeType);
	if (m_gamemode != nullptr)
	{
		m_gamemode->Init(m_circlePhysics);
		for (Circle& circle : *m_circlePhysics->GetCirleList())
		{
			m_circlePhysics->MakeSpriteRayLib(&circle);
		}
		return 0;
	}
	else
		return 1;
}

int WindowRayLib::Open()
{
	InitWindow(m_sizeX, m_sizeY, m_winName.c_str());
	SetTargetFPS(fps);
	BeginDrawing();
	ClearBackground(WHITE);
	EndDrawing();
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
	DrawFPS(10, 10);

	for (Circle& circle : *m_circlePhysics->GetCirleList())
	{
		circle.sprite->LoadSprite();
	}
	EndDrawing();
	return 0;
}

int WindowRayLib::Update()
{
	
	for (auto& circle : *m_circlePhysics->GetCirleList())
	{
		circle.sprite->Update();
	}
	
	//m_gamemode->Update();
	return 0;
}

//int WindowRayLib::MakeSprite(std::string imgPath, int SizeX, int SizeY, Position pos)
//{
//	if (Sprite::MakeSpriteRayLib("Src/Ressources/masterBall.png", SizeX, SizeY, pos) != nullptr)
//	{
//		m_circlePhysics->AddSprite(Sprite::MakeSpriteRayLib("Src/Ressources/masterBall.png", SizeX, SizeY, pos));
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
