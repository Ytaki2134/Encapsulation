#include "QuadTree.h"

QuadTree::QuadTree(QTRectangle* boundary, int capacity)
{
	m_boundary = boundary;
	m_capacity = capacity;
	m_pointList = new std::vector<QTPoint>();
}

bool QuadTree::Insert(QTPoint point)
{
	if (!m_boundary->Contains(point))
		return false;;

	if (m_pointList->size() < m_capacity)
	{
		m_pointList->push_back(point);
		return true;
	}
	else
	{
		if (!m_isDivided)
		{
			Subdivide();
			m_isDivided = true;
		}

		if (m_NorthEast->Insert(point))
			return true;
		else if (m_NorthWest->Insert(point))
			return true;
		else if (m_SouthEast->Insert(point))
			return true;
		else if (m_SouthWest->Insert(point))
			return true;
	}
}

void QuadTree::Show(WindowSDL* window)
{
	SDL_Rect* rect = new SDL_Rect();
	rect->x = m_boundary->x;
	rect->y = m_boundary->y;
	rect->w = m_boundary->w;
	rect->h = m_boundary->h;

	SDL_SetRenderDrawColor(window->GetSDLRenderer(), 0, 0, 255, 255); // set drawing color to blue
	SDL_RenderDrawRect(window->GetSDLRenderer(), rect);
	if (m_isDivided)
	{
		m_NorthEast->Show(window);
		m_NorthWest->Show(window);
		m_SouthEast->Show(window);
		m_SouthWest->Show(window);
	}
}

void QuadTree::Subdivide()
{
	QTRectangle* nw = new QTRectangle(m_boundary->x, m_boundary->y, m_boundary->w / 2, m_boundary->h / 2);
	m_NorthWest = new QuadTree(nw, 4);

	QTRectangle* ne = new QTRectangle(m_boundary->x + m_boundary->w / 2, m_boundary->y, m_boundary->w / 2, m_boundary->h / 2);
	m_NorthEast = new QuadTree(ne, 4);

	QTRectangle* sw = new QTRectangle(m_boundary->x, m_boundary->y + m_boundary->h / 2, m_boundary->w / 2, m_boundary->h / 2);
	m_SouthWest = new QuadTree(sw, 4);

	QTRectangle* se = new QTRectangle(m_boundary->x + m_boundary->w / 2, m_boundary->y + m_boundary->h / 2, m_boundary->w / 2, m_boundary->h / 2);
	m_SouthEast = new QuadTree(se, 4);
}
