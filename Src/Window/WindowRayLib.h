#pragma once
#include <iostream>
#include "Window.h"
#include<raylib.h>
class WindowRayLib : public Window
{
public:
	WindowRayLib(std::string winName, int SizeX, int SizeY);
	int Init() override;
	int Open() override;
	int IsOpen() override;
	int Clear() override;
	int Draw() override;
private:

	WindowRayLib* window = NULL;
};

