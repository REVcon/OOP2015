#include "stdafx.h"
#include "Compound.h"
#include "Cylinder.h"
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

CCompound::CCompound(void)
{
}

CCompound::~CCompound(void)
{
}

bool CCompound::AddBody(shared_ptr<CBody>const& body)
{
	if (this == body.get())
		return false;
	try
	{
		CCompound &bodyAsCompound = dynamic_cast<CCompound&>(*body);
		if (bodyAsCompound.HasBodyInside(this))
		{
			return false;
		}
	}
	catch (const bad_cast &e)
	{
		(void)e;
	}

	m_contents.push_back(body);
	return true;
}

double CCompound::GetVolume() const
{
	return accumulate(m_contents.cbegin(), m_contents.end(), 0.0, [](double sum, shared_ptr<CBody> body){ return sum + body->GetVolume(); });
}

double CCompound::GetMass() const
{
	return accumulate(m_contents.cbegin(), m_contents.end(), 0.0, [](double sum, shared_ptr<CBody> body){ return sum + body->GetMass(); });
}

double CCompound::GetDensity() const
{
	if (m_contents.size() == 0)
		throw runtime_error("Empty body has no density");

	return (GetMass() / GetVolume());
}

bool CCompound::HasBodyInside(const CBody *body) const
{
	for (auto &curBody : m_contents)
	{
		if (body == curBody.get())
		{
			return true;
		}

		try
		{
			CCompound &curBodyAsCompound = dynamic_cast<CCompound&>(*curBody);
			if (curBodyAsCompound.HasBodyInside(body))
			{
				return true;
			}
		}
		catch (const bad_cast &e)
		{
			(void)e;
		}
	}
	return false;
}

std::string CCompound::GetInformation() const
{
	std::ostringstream info;

	info << "Compound body composed of " << m_contents.size() << " bodies" << endl;
	info << "Has mass " << GetMass() << ", volume " << GetVolume() << " and density " << GetDensity() << endl;
	info << "Contents:" << endl;
	for (auto body : m_contents)
		info << body->GetInformation() << endl;

	return info.str();
}
