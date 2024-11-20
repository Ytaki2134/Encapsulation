#pragma once
#include "Sprite.h"

class SpriteRayLib : public Sprite
{
public:
	SpriteRayLib();
	int LoadSprite() override;
	int GetSprite() override;
	int Update() override;

	Rectangle m_rect;
	Image surface;

};

