#include "GameMode.h"


GameMode* GameMode::MakeGameMode(GameModeType gameMode)
{
	switch (gameMode)
	{
	case BOUNCING_BALLS:
		break;
	default:
		return nullptr;
		break;
	}
}
