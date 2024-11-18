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

int WindowRayLib::Open()
{
	InitWindow(m_sizeX, m_sizeY,m_winName.c_str());
	SetTargetFPS(60);
	BeginDrawing();
	ClearBackground(WHITE);
	EndDrawing();
	return 0;
}

int WindowRayLib::IsOpen()
{
	return 0;
}

int WindowRayLib::Clear()
{

	return 0;
}

int WindowRayLib::Draw()
{
	
	return 0;
}
