#include "SpriteSDL.h"
#include "../Window/WindowSDL.h"

SpriteSDL::SpriteSDL()
{

}

int SpriteSDL::LoadSprite()
{
	SDL_BlitScaled(m_surface, NULL, m_SDLwinSurface, &m_rect);
	return 0;
}

int SpriteSDL::GetSprite()
{
	return 0;
}
