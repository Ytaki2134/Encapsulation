#pragma once
#include <vector>
#include "../Sprite/Sprite.h"

enum GameModeType
{
	BOUNCING_BALLS
};

class GameMode {
public:
	virtual void Update() = 0;
	virtual void CheckWin() = 0;
	virtual void AddSprite() = 0;

	static GameMode* MakeGameMode(GameModeType gameMode);
protected:
	std::vector<Sprite> sprites;

private: 
};