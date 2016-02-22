#include "stdafx.h"
#include "Canvas.h"


bool CCanvas::ValidCoords(int x, int y) const
{
	if (x < 0 || y < 0)
	{
		return false;
	}
	unsigned uX = x;
	unsigned uY = y;
	return !(uX > m_width || uY > m_height);
}

char CCanvas::s_nullSymbol = ' ';

CCanvas::CCanvas(unsigned width, unsigned height)
{
	m_width = width;
	m_height = height;
	for (unsigned i = 0; i <= height; ++i)
	{
		std::vector<char> curLine;
		for (unsigned j = 0; j <= width; ++j)
		{
			curLine.push_back(s_nullSymbol);
		}
		m_canvas.push_back(curLine);
	}
}

CCanvas::~CCanvas()
{
}

unsigned CCanvas::GetWidth() const
{
	return m_width;
}

unsigned CCanvas::GetHeight() const
{
	return m_height;
}

char CCanvas::GetPixel(int x, int y) const
{
	if (!ValidCoords(x, y))
	{
		return s_nullSymbol;
	}
	return m_canvas[y][x];
}


void CCanvas::Write(std::ostream &ostream) const
{
	for (unsigned i = 0; i <= m_height; ++i)
	{
		for (unsigned j = 0; j <= m_width; ++j)
		{
			ostream << m_canvas[i][j];
		}
		ostream << std::endl;
	}
}

void CCanvas::Clear(char code)
{
	if (code < s_nullSymbol)
	{
		return;
	}

	for (unsigned i = 0; i <= m_height; ++i)
	{
		for (unsigned j = 0; j <= m_width; ++j)
		{
			m_canvas[i][j] = code;
		}
	}
}

void CCanvas::SetPixel(int x, int y, char code)
{
	if (code < s_nullSymbol || !ValidCoords(x, y))
	{
		return;
	}
	m_canvas[y][x] = code;
}