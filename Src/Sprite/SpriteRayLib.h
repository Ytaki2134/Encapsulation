#pragma once
#include "Sprite.h"

class SpriteRayLib : public Sprite
{
public:
	SpriteRayLib();
	int LoadTexture();
	int LoadSprite() override;
	int GetSprite_x() override;
	int GetSprite_y() override;
	int GetSprite_w() override;
	int GetSprite_h() override;
	int Update(int,int) override;
	void GetSizeWin(int* w, int* h) override;
public:
	Rectangle m_rect;
	Texture2D texture;
	Image surface ;

};

