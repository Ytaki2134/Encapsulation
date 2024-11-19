#pragma once
#include <iostream>
#include <string>
#include <SDL.h>

struct Position
{
	Position(int posX, int posY) { x = posX; y = posY; }
	float x;
	float y;
};

class Sprite
{
public:
	virtual void LoadSprite(std::string pathImage) = 0;
	virtual void GetSprite() = 0;

	static SDL_Surface* MakeSpriteSDL(std::string imgPath, int SizeX, int SizeY, Position pos, SDL_Window* window);
	static SDL_Surface* MakeSpriteRayLib(std::string imgPath, int SizeX, int SizeY, Position pos, SDL_Window* window);

protected:
	float x, y;
	std::string path;
};

