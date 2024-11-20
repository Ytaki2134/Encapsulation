#pragma once
#include <vector>

struct Circle
{
	Circle(float posX, float posY, float radius) { x = posX; y = posY; r = radius; }
	float x, y;
	float r;
	float vx = 0, vy = 0;
	float ax = 0, ay = 0;
};

class BallCollider
{
public:
	BallCollider();
	bool Init();
	bool Update();
private :
	std::vector<std::pair<float, float>> m_modelCircle;
};

