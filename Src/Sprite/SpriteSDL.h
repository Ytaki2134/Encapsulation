#pragma once
#include <SDL.h>
#include "Sprite.h"

class WindowSDL;

class SpriteSDL : public Sprite
{
public:
	SpriteSDL();
	int LoadSprite() override;
	int GetSprite() override;
public:
	SDL_Rect m_rect;
	SDL_Texture* m_texture = nullptr;
	SDL_Renderer* m_renderer = nullptr;
private:
	//Circle m_collider;
};

