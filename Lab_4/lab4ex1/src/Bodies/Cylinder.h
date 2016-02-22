#pragma once
#include "SolidBody.h"

class CCylinder final:
	public CSolidBody
{
public:
	CCylinder(double radius, double height, double density);
	~CCylinder(void);

	double GetRadius() const;
	double GetHeight() const;

	virtual double GetVolume() const override;
	virtual std::string GetInformation() const override;

private:
	double m_height, m_radius;
};

