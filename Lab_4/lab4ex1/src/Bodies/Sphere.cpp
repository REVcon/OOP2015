#include "stdafx.h"
#include "Sphere.h"


CSphere::CSphere(double radius, double density)
	: CSolidBody(density)
	, m_radius(radius)
{
}

CSphere::~CSphere(void)
{
}

double CSphere::GetRadius() const
{
	return m_radius;
}

double CSphere::GetVolume() const
{
	return (4 * M_PI / 3 * pow(m_radius, 3));
}

std::string CSphere::GetInformation() const
{
	std::ostringstream info;

	info << "Sphere with radius " << GetRadius();
	info << " and density " << GetDensity();

	return info.str();
}
