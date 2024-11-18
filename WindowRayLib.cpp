#include "WindowRayLib.h"
#include"raylib.h"
WindowRayLib::WindowRayLib()
{
	
}

int WindowRayLib::Init()
{

}

int WindowRayLib::Open()
{
	InitWindow(450, 450, "basic window");
	SetTargetFPS(60);
}

int WindowRayLib::IsOpen()
{

}

int WindowRayLib::Clear()
{
	BeginDrawing();
	ClearBackground(BLACK);
	EndDrawing();
}

int WindowRayLib::Draw()
{
	BeginDrawing();
	EndDrawing();
}
