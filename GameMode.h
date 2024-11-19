#pragma once
#include <vector>
#include "Src/Sprite/Sprite.h"

class GameMode {
public:
	virtual void Update() = 0;
	virtual void CheckWin() = 0;

protected:
	std::vector<Sprite> sprites;

private: 
};