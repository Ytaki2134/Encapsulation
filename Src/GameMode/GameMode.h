#pragma once
#include <vector>
#include "../Sprite/Sprite.h"

class Window;
class CirclePhysics;

enum GameModeType
{
	BOUNCING_BALLS
};

class GameMode {
public:
	virtual void Init(CirclePhysics* circlePhysics) = 0;
	virtual void Update() = 0;
	virtual void CheckWin() = 0;

	virtual Circle* MakeCircleObject(float x, float y, float r, std::string imgPath);
	static GameMode* MakeGameMode(GameModeType gameMode);
protected:
	CirclePhysics* m_circlePhysics;
};