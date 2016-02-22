#pragma once
class CBody
{
public:
	CBody(void);
	// в базовом классе деструктор следует делать виртуальным
	virtual ~CBody(void);

	virtual double GetVolume() const = 0;

	virtual double GetDensity() const = 0;

	virtual double GetMass() const = 0;

	virtual std::string GetInformation() const = 0;
};

