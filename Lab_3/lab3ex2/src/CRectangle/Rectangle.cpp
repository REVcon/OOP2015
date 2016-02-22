#include "stdafx.h"
#include "Rectangle.h"
#include <algorithm>


CRectangle::CRectangle(int left, int top, int width, int height)
	: m_height(std::max(0, height))
	, m_width(std::max(0, width))
	, m_left(left)
	, m_top(top)
{
}

CRectangle::~CRectangle()
{
}

unsigned CRectangle::GetWidth() const
{
	return m_width;
}

void CRectangle::SetWidth(int width)
{
	m_width = std::max(0, width);
}

unsigned CRectangle::GetHeight() const
{
	return m_height;
}

void CRectangle::SetHeight(int height)
{
	m_height = std::max(0, height);
}

void CRectangle::SetLeft(int xCoordinate)
{
	m_left = xCoordinate;
}

unsigned CRectangle::GetLeft() const
{
	return m_left;
}

unsigned CRectangle::GetRight() const
{
	return m_left + m_width;
}

void CRectangle::SetTop(int yCoordinate)
{
	m_top = yCoordinate;
}

void CRectangle::SetRight(int right)
{
	m_width = right > m_left ? right - m_left : m_width;
}

unsigned CRectangle::GetBottom() const
{
	return m_top + m_height;
}

void CRectangle::SetBottom(int bottom)
{
	m_height = bottom > m_top ? bottom - m_top : m_height;
}

unsigned CRectangle::GetTop() const
{
	return m_top;
}

unsigned CRectangle::GetPerimetr() const
{
	return (m_width + m_height) * 2;
}

unsigned CRectangle::GetSquare() const
{
	return (m_height * m_width);
}

void CRectangle::Move(int dx, int dy)
{
	m_left += dx;
	m_top += dy;
}

void CRectangle::Scale(int sx, int sy)
{
	if (sx > 0 && sy > 0)
	{
		m_width *= sx;
		m_height *= sy;
	}
}

bool CRectangle::Intersect(CRectangle const &other)
{
	int lx = m_left, ly = m_top;
	int rx = m_left + m_width, ry = m_top + m_height;
	int lx1 = other.m_left, ly1 = other.m_top;
	int rx1 = lx1 + other.m_width, ry1 = ly1 + other.m_height;

	int maxLX = std::max(lx, lx1), minRX = std::min(rx, rx1);
	int maxLY = std::max(ly, ly1), minRY = std::min(ry, ry1);
	if (minRX > maxLX && minRY > maxLY)
	{
		m_left = maxLX;
		m_top = maxLY;
		m_width = minRX - maxLX;
		m_height = minRY - maxLY;
		return true;
	}

	m_width = 0;
	m_height = 0;
	return false;
}
