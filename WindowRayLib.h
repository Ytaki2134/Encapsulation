#pragma once
#include "Window.h"

class WindowRayLib : public Window
{
public:
	WindowRayLib();
	int Init() override;
	int Open() override;
	int IsOpen() override;
	int Clear() override;
	int Draw() override;
};

