#include "Sprite.h"
#include "SpriteSDL.h"
#include "SpriteRayLib.h"

Sprite* Sprite::MakeSpriteSDL(std::string imgPath, int SizeX, int SizeY, Position pos, SDL_Window* window)
{
	SpriteSDL* tempSprite = new SpriteSDL();
	SDL_Surface* surface = SDL_LoadBMP(imgPath.c_str());
	if (surface)
	{
		SDL_Rect dest = { pos.x, pos.y, SizeX, SizeY };

		tempSprite->m_rect = dest;
		tempSprite->m_surface = surface;
		tempSprite->m_SDLwinSurface = SDL_GetWindowSurface(window);
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
		return mysprite;
	}
	else {
		std::cout << "Error Loading Sprite: " << SDL_GetError() << std::endl;
		return nullptr;
	}
}
