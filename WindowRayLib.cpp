#include "WindowRayLib.h"

WindowRayLib::WindowRayLib(std::string winName, int SizeX, int SizeY)
{
	m_winName = winName;
	m_sizeX = SizeX;
	m_sizeY = SizeY;
}

int WindowRayLib::Init()
{
	return 0;
}

int WindowRayLib::Open(std::string winName, int SizeX, int SizeY)
{
	InitWindow(SizeX, SizeY,winName.c_str());
	SetTargetFPS(60);
	return 0;
}

int WindowRayLib::IsOpen()
{
	return 0;
}

int WindowRayLib::Clear()
{
	BeginDrawing();
	ClearBackground(BLACK);
	EndDrawing();
	return 0;
}

int WindowRayLib::Draw()
{
	BeginDrawing();
	EndDrawing();
	return 0;
}
