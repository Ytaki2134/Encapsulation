#pragma once
#include <string>

class Sprite
{
public:
	virtual void LoadSprite() = 0;
	virtual void GetSprite() = 0;

	static void MakeSpriteSDL(std::string imgPath, int SizeX, int SizeY);
	static void MakeSpriteRayLib(std::string imgPath, int SizeX, int SizeY);

protected:
	float x, y;
};

