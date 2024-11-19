#include "Sprite.h"

SDL_Surface* Sprite::MakeSpriteSDL(std::string imgPath, int SizeX, int SizeY, Position pos, SDL_Window* window)
{
	SDL_Surface* pSprite = SDL_LoadBMP(imgPath.c_str());
	if (pSprite)
	{
		SDL_Rect dest = { pos.x, pos.y, SizeX, SizeY };
		SDL_BlitScaled(pSprite, NULL, SDL_GetWindowSurface(window), &dest);

		SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
		return pSprite;
	}
	else
	{
		std::cout << "Error Loading Sprite: " << SDL_GetError() << std::endl;
		system("pause");
		// End the program
		return nullptr;
	}
}

SDL_Surface* Sprite::MakeSpriteRayLib(std::string imgPath, int SizeX, int SizeY, Position pos, SDL_Window* window)
{
	return nullptr;
}
