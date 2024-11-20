#include "SpriteRayLib.h"
#include "../Window/WindowRayLib.h"


SpriteRayLib::SpriteRayLib()
{

}

int SpriteRayLib::LoadSprite()
{
	ImageResize(&surface, m_rect.width, m_rect.height);
	DrawTexture(LoadTextureFromImage(surface) ,m_rect.x ,m_rect.y ,WHITE);

	return 0;
}

int SpriteRayLib::GetSprite()
{
	return 0;
}

int SpriteRayLib::Update()
{

	if (((m_rect.x + velos_x + m_rect.width ) > GetScreenWidth()) ||
		((m_rect.x + velos_x  ) < 0)) velos_x *= -1;
	if (((m_rect.y +velos_y+ m_rect.height ) > GetScreenHeight()) ||
		((m_rect.y + velos_y  ) < 0)) velos_y *= -1;

	m_rect.x += velos_x;
	//m_rect.width += velos_x;
	m_rect.y+= velos_y;
	//m_rect.height += velos_y;
	return 0;
}

