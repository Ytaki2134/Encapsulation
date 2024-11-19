#pragma once
#include <iostream>
#include "Window.h"
#include<raylib.h>
class WindowRayLib : public Window
{
public:
	WindowRayLib(std::string winName, int SizeX, int SizeY);
	int Init(GameModeType* gameModeType) override;
	int Open() override;
	int IsOpen() override;
	int Clear() override;
	int Draw() override;
	int MakeSprite(std::string imgPath, int SizeX, int SizeY, Position pos) override;
};

