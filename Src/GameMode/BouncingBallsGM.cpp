#include "BouncingBallsGM.h"
#include "../Window/Window.h"

BouncingBallsGM::BouncingBallsGM()
{

}

void BouncingBallsGM::Init(Window* window)
{
	//BOUNCING BALLS SCENE
	m_window = window;

	//INIT SPRITES
	m_window->MakeSprite("Src/Ressources/masterBall.bmp", 40, 40, Position(20, 20));
	m_window->MakeSprite("Src/Ressources/masterBall.bmp", 40, 40, Position(60, 60));
}

void BouncingBallsGM::Update()
{

}

void BouncingBallsGM::CheckWin()
{

}


