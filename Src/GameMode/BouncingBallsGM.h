#pragma once
#include "GameMode.h"

class BouncingBallsGM : public GameMode
{
public:
	BouncingBallsGM();
	void Init(Window* window) override;
	void Update() override;
	void CheckWin() override;
};

