#pragma once
#include "solidbody.h"
#include "Sphere.h"

class CCone final :
	public CSolidBody
{
public:
	CCone(double radius, double height, double density);
	~CCone(void);

	double GetRadius() const;
	double GetHeight() const;

	virtual double GetVolume() const override;
	virtual std::string GetInformation() const override;

private:
	double m_height, m_radius;
};

