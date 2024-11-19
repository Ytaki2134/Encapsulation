#pragma once
#include "Sprite.h"

class SpriteRayLib : public Sprite
{
public:
	SpriteRayLib();
	void LoadSprite(std::string pathImage) override;
	void GetSprite() override;


};

