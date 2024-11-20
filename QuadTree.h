#pragma once
#include <vector>
#include <SDL.h>
#include "Src/Window/WindowSDL.h"

struct QTPoint {
	QTPoint(int posX, int posY) { x = posX; y = posY; }
	int x;
	int y;
};

struct QTRectangle {
	QTRectangle(int posX, int posY, int width, int height) 
	{ 
		x = posX;
		y = posY;
		w = width;
		h = height;
	}

	bool Contains(QTPoint point)
	{
		return (
			point.x >= x - w &&
			point.x <= x + w &&
			point.y >= y - h &&
			point.y <= y + h
			);
	};

	int x;
	int y;
	int w;
	int h;
};

class QuadTree
{
public:
	QuadTree(QTRectangle* boundary, int capacity);
	bool Insert(QTPoint point);
	void Show(WindowSDL* window);
private:
	void Subdivide();
private:
	QTRectangle* m_boundary;
	int m_capacity;
	std::vector<QTPoint>* m_pointList;

	bool m_isDivided = false;

	//SUBQUADTREES
	QuadTree* m_NorthWest = nullptr;
	QuadTree* m_NorthEast = nullptr;
	QuadTree* m_SouthWest = nullptr;
	QuadTree* m_SouthEast = nullptr;
};

