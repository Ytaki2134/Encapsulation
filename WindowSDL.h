#pragma once
#include "Window.h"
class WindowSDL : public Window
{
public:
	WindowSDL();
	void Init() override;
	void Open() override;
	void IsOpen() override;
	void Clear() override;
	void Draw() override;
};

