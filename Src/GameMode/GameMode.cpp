#include "GameMode.h"
#include "BouncingBallsGM.h"
#include "../../Src/Physics/CirclePhysics.h"


void GameMode::MakeCircleObject(float x, float y, float r, std::string imgPath)
{
	m_circlePhysics->MakeCircle(imgPath, x, y, r);
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

//void GameMode::AddSprite(Sprite* sprite)
//{
//	m_sprites.push_back(sprite);
//}
//
//std::vector<Sprite*> GameMode::GetSpriteVector()
//{
//	return m_sprites;
//}
