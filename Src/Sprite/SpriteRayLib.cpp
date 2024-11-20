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

