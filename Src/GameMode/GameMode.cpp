#include "GameMode.h"
#include "BouncingBallsGM.h"
#include "../../Src/Physics/CirclePhysics.h"


Circle* GameMode::MakeCircleObject(float x, float y, float r, std::string imgPath)
{
	return m_circlePhysics->MakeCircle(imgPath, x, y, r);
}

GameMode* GameMode::MakeGameMode(GameModeType gameMode)
{
	switch (gameMode)
	{
	case BOUNCING_BALLS:
		return new BouncingBallsGM();
		break;
	default:
		return nullptr;
		break;
	}
}
