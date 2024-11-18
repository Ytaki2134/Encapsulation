#pragma once
class Sprite
{
public:
	Sprite();
	virtual void LoadSprite();
	virtual void GetSprite();

protected:
	float x, y;
};

