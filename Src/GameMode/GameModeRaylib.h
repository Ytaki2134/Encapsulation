#pragma once
#include "GameMode.h"
class GameModeRaylib : public GameMode {

public:
	void Update() override;
	void CheckWin() override;
	void AddSprite() override;

};