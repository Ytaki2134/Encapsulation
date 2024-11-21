#include "SpriteRayLib.h"
#include "../Window/WindowRayLib.h"


SpriteRayLib::SpriteRayLib()
{

}

int SpriteRayLib::LoadTexture()
{
	ImageResize(&surface, m_rect.width, m_rect.height);

	return 0;
}


int SpriteRayLib::LoadSprite()
{
	if (texture.id == 0) {
		texture = LoadTextureFromImage(surface);
	}
	DrawTexture(texture,m_rect.x ,m_rect.y ,WHITE);
	return 0;
}

int SpriteRayLib::GetSprite_x()
{
	return m_rect.x;
}
int SpriteRayLib::GetSprite_y()
{
	return m_rect.y;
}
int SpriteRayLib::GetSprite_w()
{
	return m_rect.width;
}
int SpriteRayLib::GetSprite_h()
{
	return m_rect.height;
}

int SpriteRayLib::Update(int x, int y )
{
	m_rect.x = x;
	m_rect.y = y;
	return 0;
}

void SpriteRayLib::GetSizeWin(int* w, int* h)
{
	*w =  (int)GetScreenWidth();
	*h = (int)GetScreenHeight();
}

