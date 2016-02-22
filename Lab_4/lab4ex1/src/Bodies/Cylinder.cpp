#include "stdafx.h"
#include "Cylinder.h"
#include <sstream>

CCylinder::CCylinder(double radius, double height, double density)
	:CSolidBody(density)
	, m_radius(radius)
	, m_height(height)
{
}


CCylinder::~CCylinder(void)
{
}

double CCylinder::GetRadius() const
{
	return m_radius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

double CCylinder::GetVolume() const
{
	return M_PI * m_radius * m_radius * m_height;
}

std::string CCylinder::GetInformation() const
{
	std::ostringstream info;

	info << "Cylinder with base radius " << GetRadius();
	info << ", height " << GetHeight();
	info << " and density " << GetDensity();

	return info.str();
}
