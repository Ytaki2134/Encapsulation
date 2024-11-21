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

int SpriteSDL::GetSprite()
{
	return 0;
}

int SpriteSDL::Update()
{
	if (((m_rect.x + velos_x + m_rect.w) > m_SDLwinSurface->w) ||
		((m_rect.x + velos_x) < 0)) velos_x *= -1;
	if (((m_rect.y + velos_y + m_rect.h) > m_SDLwinSurface->h) ||
		((m_rect.y + velos_y) < 0)) velos_y *= -1;

	m_rect.x += velos_x;
	//m_rect.width += velos_x;
	m_rect.y += velos_y;
	//m_rect.height += velos_y;
	return 0;
}
