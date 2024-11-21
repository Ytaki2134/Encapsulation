#include "BouncingBallsGM.h"
#include "../Window/Window.h"

BouncingBallsGM::BouncingBallsGM()
{

}

void BouncingBallsGM::Init(CirclePhysics* circlePhysics)
{
	//BOUNCING BALLS SCENE
	m_circlePhysics = circlePhysics;

	//INIT Scene Objects
	MakeCircleObject(40, 40, 20, "Src/Ressources/masterBall.png");
	MakeCircleObject(60, 40, 20, "Src/Ressources/masterBall.png");
}

void BouncingBallsGM::Update()
{

}

void BouncingBallsGM::CheckWin()
{

}


