#include "stdafx.h"
#include "Cone.h"
#include <sstream>

CCone::CCone(double radius, double height, double density)
	: CSolidBody(density)
	, m_radius(radius)
	, m_height(height)
{
}

CCone::~CCone(void)
{
}

double CCone::GetRadius() const
{
	return m_radius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return (1.0 / 3) * (M_PI * m_radius * m_radius) * m_height;
}

std::string CCone::GetInformation() const
{
	std::ostringstream info;

	info << "Cone with base radius " << GetRadius();
	info << ", height " << GetHeight();
	info << " and density " << GetDensity();

	return info.str();
}
