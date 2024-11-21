#pragma once
#include <SDL.h>
#include "Sprite.h"

class WindowSDL;

class SpriteSDL : public Sprite
{
public:
	SpriteSDL();
	int LoadSprite() override;
	int GetSprite_x() override;
	int GetSprite_y() override;
	int GetSprite_w() override;
	int GetSprite_h() override;
	int Update(int,int) override;
	void GetSizeWin(int* w, int* h) override;
public:
	SDL_Rect m_rect;
	SDL_Texture* m_texture = nullptr;
	SDL_Renderer* m_renderer = nullptr;
private:
	//Circle m_collider;
};

