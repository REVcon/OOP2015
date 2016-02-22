#pragma once
#include "Solidbody.h"

class CSphere final : public CSolidBody
{
public:
	CSphere(double radius, double density);
	~CSphere(void);

	double GetRadius() const;
	// ������, ���������������� ������ ������� �������, ������������� 
	// ��������� �� �������������� override
	double GetVolume() const override final;

	std::string CSphere::GetInformation() const;

private:
	double m_radius;
};

