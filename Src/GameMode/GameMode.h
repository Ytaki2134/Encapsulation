#pragma once
#include <vector>
#include "../Sprite/Sprite.h"

class Window;
class CirclePhysics;

enum GameModeType
{
	BOUNCING_BALLS
};

class GameMode {
public:
	virtual void Init(CirclePhysics* circlePhysics) = 0;
	virtual void Update() = 0;
	virtual void CheckWin() = 0;

	virtual void MakeCircleObject(float x, float y, float r, std::string imgPath);
	//virtual void AddSprite(Sprite* sprite);
	//virtual std::vector<Sprite*> GetSpriteVector();
	static GameMode* MakeGameMode(GameModeType gameMode);
protected:
	CirclePhysics* m_circlePhysics;
	//std::vector<Sprite*> m_sprites;
	//Window* m_window = nullptr;
};