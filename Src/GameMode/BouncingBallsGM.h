#pragma once
#include "GameMode.h"

class BouncingBallsGM : public GameMode
{
public:
	BouncingBallsGM();
	void Init(CirclePhysics* circlePhysics) override;
	void Update() override;
	void CheckWin() override;
};

