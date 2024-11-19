#pragma once
#include "Sprite.h"

class SpriteSDL : public Sprite
{
	SpriteSDL();
	void LoadSprite() override;
	void GetSprite() override;
};

