#pragma once
#include "Src/GameMode/GameMode.h"
class GameModeRaylib : public GameMode {

public:
	GameModeRaylib();
	void Update() override;
	void CheckWin() override;
};