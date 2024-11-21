#pragma once
#include <vector>
#include <string>

class Sprite;
struct SDL_Window;

struct Circle
{
	Circle() {};
	Circle(float posX, float posY, float radius, std::string imgPath) { x = posX; y = posY; r = radius; this->imgPath = imgPath; }
	int Update();;
	float x, y;
	float r;
	float vx = 0, vy = 0;
	float ax = 0, ay = 0;

	std::string imgPath;
	Sprite* sprite;
	int id;
};

class CirclePhysics
{
public:
	CirclePhysics();
	bool Init();
	bool Update();
	Circle* MakeCircle(std::string imgPath, float x, float y, float r);
	void MakeSpriteSDL(Circle* targetCircle);
	void MakeSpriteRayLib(Circle* targetCircle);
	void SetVelocityRandom(Circle* targetCircle);

	std::vector<Circle>* GetCirleList();
	void SetWindow(SDL_Window* window);
private:
	Circle* AddCircle(std::string imgPath, float x, float y, float r = 5.0f);
private:
	std::vector<std::pair<float, float>> m_modelCircle;
	std::vector<Circle> m_circleList;
	SDL_Window* m_SDLWindow;
};

