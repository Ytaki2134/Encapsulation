#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <raylib.h>

struct Position
{
	Position(int posX, int posY) { x = posX; y = posY; }
	float x;
	float y;
};

class SpriteSDL;
class SpriteRayLib;
class Window;

class Sprite
{
public:
	virtual int LoadSprite() = 0;
	virtual int GetSprite() = 0;
	virtual int Update() = 0;
	static Sprite* MakeSpriteSDL(std::string imgPath, int SizeX, int SizeY, Position pos, SDL_Window* window);
	static Sprite* MakeSpriteRayLib(std::string imgPath, int SizeX, int SizeY, Position pos);

protected:
	std::string m_path;
	float velos_x = 1;
	float velos_y = 1;
};

