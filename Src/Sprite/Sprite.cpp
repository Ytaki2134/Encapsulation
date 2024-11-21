#include "Sprite.h"
#include "SpriteSDL.h"
#include "SpriteRayLib.h"

Sprite* Sprite::MakeSpriteSDL(std::string imgPath, int SizeX, int SizeY, Position pos, SDL_Window* window)
{
	SpriteSDL* tempSprite = new SpriteSDL();

	SDL_Surface* surface = IMG_Load(imgPath.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(SDL_GetRenderer(window), surface);

	if (texture)
	{
		SDL_Rect dest = { pos.x, pos.y, SizeX, SizeY };

		tempSprite->m_rect = dest;
		tempSprite->m_texture = texture;
		tempSprite->m_renderer = SDL_GetRenderer(window);
		return tempSprite;
	}
	else
	{
		std::cout << "Error Loading Sprite: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return nullptr;
	}
}

Sprite* Sprite::MakeSpriteRayLib(std::string imgPath, int SizeX, int SizeY, Position pos)
{
	SpriteRayLib* mysprite = new SpriteRayLib();
	Image surface = LoadImage(imgPath.c_str());
	if (&surface) {

		Rectangle rect = { pos.x, pos.y, SizeX, SizeY };
		mysprite->m_rect = rect;
		mysprite->surface = surface;
		mysprite->LoadTexture();

		return mysprite;
	}
	else {
		std::cout << "Error Loading Sprite: " << SDL_GetError() << std::endl;
		return nullptr;
	}
}
