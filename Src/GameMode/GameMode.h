#pragma once
#include <vector>
#include "../Sprite/Sprite.h"

class Window;

enum GameModeType
{
	BOUNCING_BALLS
};

class GameMode {
public:
	virtual void Init(Window* window) = 0;
	virtual void Update() = 0;
	virtual void CheckWin() = 0;

	virtual void AddSprite(Sprite* sprite);
	virtual std::vector<Sprite*> GetSpriteVector();
	static GameMode* MakeGameMode(GameModeType gameMode);
protected:
	std::vector<Sprite*> m_sprites;
	Window* m_window = nullptr;
};