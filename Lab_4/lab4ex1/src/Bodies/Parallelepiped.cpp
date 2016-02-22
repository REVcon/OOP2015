#include "stdafx.h"
#include "Parallelepiped.h"
#include <sstream>

CParallelepiped::CParallelepiped(double width, double height, double depth, double density)
	: CSolidBody(density),
	m_width(width), m_height(height), m_depth(depth)
{
}


CParallelepiped::~CParallelepiped(void)
{
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}

double CParallelepiped::GetVolume() const
{
	return GetWidth() * GetHeight() * GetDepth();
}

std::string CParallelepiped::GetInformation() const
{
	std::ostringstream info;

	info << "Parallelepiped with width " << GetWidth();
	info << ", height " << GetHeight();
	info << ", depth " << GetDepth();
	info << " and density " << GetDensity();

	return info.str();
}
