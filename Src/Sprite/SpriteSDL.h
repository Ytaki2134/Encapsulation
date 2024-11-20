#pragma once
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
	SDL_Surface* m_surface = nullptr;
	SDL_Surface* m_SDLwinSurface = nullptr;
private:
	//Circle m_collider;
};

