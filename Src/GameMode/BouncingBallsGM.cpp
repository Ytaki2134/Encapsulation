#include "BouncingBallsGM.h"
#include "../Window/Window.h"
#include "../../Src/Physics/CirclePhysics.h"

BouncingBallsGM::BouncingBallsGM()
{

}

void BouncingBallsGM::Init(CirclePhysics* circlePhysics)
{
	//BOUNCING BALLS SCENE
	m_circlePhysics = circlePhysics;

	int radius = 20;
	//INIT Scene Objects
	for (int i = 0; i < 100; i++)
	{
		int randomNum = rand() % ((400 - radius) - 0 + 1) + 0;
		int randomNum2 = rand() % ((400 - radius) - 0 + 1) + 0;
		Circle* currentCircle = MakeCircleObject(randomNum, randomNum2, radius, "Src/Ressources/masterBall.png");
		m_circlePhysics->SetVelocityRandom(currentCircle);
	}

}

void BouncingBallsGM::Update()
{
	int radius = 20;
	//INIT Scene Objects
	int randomNum = rand() % ((400 - radius) - 0 + 1) + 0;
	int randomNum2 = rand() % ((400 - radius) - 0 + 1) + 0;
	Circle* currentCircle = MakeCircleObject(randomNum, randomNum2, radius, "Src/Ressources/masterBall.png");
	m_circlePhysics->SetVelocityRandom(currentCircle);
}

void BouncingBallsGM::CheckWin()
{

}


