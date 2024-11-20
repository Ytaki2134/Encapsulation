#pragma once
#include "Sprite.h"

class SpriteSDL : public Sprite
{
	SpriteSDL();
	void LoadSprite(std::string pathImage) override;
	void GetSprite() override;
};

