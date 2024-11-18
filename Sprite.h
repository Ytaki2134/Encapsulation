#pragma once
class Sprite
{
	Sprite();
	virtual void LoadSprite();
	virtual void GetSprite();

protected:
	float x, y;
};

