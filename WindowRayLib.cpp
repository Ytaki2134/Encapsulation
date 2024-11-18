#include "WindowRayLib.h"
#include"raylib.h"
WindowRayLib::WindowRayLib()
{
	
}

void WindowRayLib::Init()
{

}

void WindowRayLib::Open()
{
	InitWindow(450, 450, "basic window");
	SetTargetFPS(60);
}

void WindowRayLib::IsOpen()
{

}

void WindowRayLib::Clear()
{
	BeginDrawing();
	ClearBackground(BLACK);
	EndDrawing();
}

void WindowRayLib::Draw()
{
	BeginDrawing();
	EndDrawing();
}
