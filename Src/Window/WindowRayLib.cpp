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
	return 0;
}

int WindowRayLib::IsOpen()
{
	if (IsWindowReady)
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
	DrawTexture(LoadTexture("Src/Ressources/masterBall.png"), 50, 50, WHITE);
	EndDrawing();
	return 0;
}

int WindowRayLib::MakeSprite(std::string imgPath, int SizeX, int SizeY, Position pos)
{
	return 0;
}
