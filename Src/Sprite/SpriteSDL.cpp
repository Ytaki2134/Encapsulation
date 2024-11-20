#include "SpriteSDL.h"
#include "../Window/WindowSDL.h"

SpriteSDL::SpriteSDL()
{

}

int SpriteSDL::LoadSprite()
{
	SDL_BlitScaled(m_surface, NULL, m_SDLwinSurface, &m_rect);
	//bm_collider = new Circle(m_rect.x, m_rect.y, m_rect.w);
	return 0;
}

int SpriteSDL::GetSprite()
{
	return 0;
}

int SpriteSDL::Update()
{
	return 0;
}
