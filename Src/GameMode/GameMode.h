#pragma once
#include <vector>
#include "../Sprite/Sprite.h"

class GameMode {
public:
	virtual void Update() = 0;
	virtual void CheckWin() = 0;
	virtual void AddSprite() = 0;

protected:
	std::vector<Sprite> sprites;

private: 
};