#include "GameMode.h"
#include "BouncingBallsGM.h"


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

void GameMode::AddSprite(Sprite* sprite)
{
	m_sprites.push_back(sprite);
}

std::vector<Sprite*> GameMode::GetSpriteVector()
{
	return m_sprites;
}
