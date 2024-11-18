#pragma once
#include "Window.h"

class WindowRayLib : public Window
{
public:
	WindowRayLib();
	void Init() override;
	void Open() override;
	void IsOpen() override;
	void Clear() override;
	void Draw() override;
};

