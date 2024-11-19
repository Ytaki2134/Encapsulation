#pragma once
#include "GameMode.h"

class BouncingBallsGM : public GameMode
{
public:
	BouncingBallsGM();
	void Update() override;
	void CheckWin() override;
};

