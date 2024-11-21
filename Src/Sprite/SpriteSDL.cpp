#include "SpriteSDL.h"
#include "../Window/WindowSDL.h"

SpriteSDL::SpriteSDL()
{

}

int SpriteSDL::LoadSprite()
{
	//SDL_BlitScaled(m_texture, NULL, m_SDLwinSurface, &m_rect);
	SDL_RenderCopy(m_renderer, m_texture, NULL, &m_rect);
	//bm_collider = new Circle(m_rect.x, m_rect.y, m_rect.w);
	return 0;
}

int SpriteSDL::GetSprite_x()
{
	return m_rect.x;
}

int SpriteSDL::GetSprite_y()
{
	return m_rect.y;
}

int SpriteSDL::GetSprite_w()
{
	return m_rect.w;
}

int SpriteSDL::GetSprite_h()
{
	return m_rect.h;
}

int SpriteSDL::Update(int x, int y)
{
	m_rect.x = x;
	m_rect.y = y;
	return 0;
}
void SpriteSDL::GetSizeWin(int * w,int*  h) {

	SDL_GetRendererOutputSize(m_renderer, w, h);
}
