#pragma once
#include "Window.h"
#include<raylib.h>
class WindowRayLib : public Window
{
public:
	WindowRayLib();
	int Init() override;
	int Open(std::string winName, int SizeX, int SizeY) override;
	int IsOpen() override;
	int Clear() override;
	int Draw() override;
};

