#include "stdafx.h"
#include "Rational.h"
#include <iostream>
#include <utility>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

double  CRational::ToDouble() const
{
	return (double)m_numerator / (double)m_denominator;
}

CRational const CRational::operator +() const
{
	return *this;
}

CRational const CRational::operator -() const
{
	return CRational(-m_numerator, m_denominator);
}

const CRational operator + (const CRational &num1, const CRational &num2)
{
	int numerator = num1.GetNumerator() * num2.GetDenominator() + num2.GetNumerator() * num1.GetDenominator();
	int denominator = num1.GetDenominator() * num2.GetDenominator();
	return CRational(numerator, denominator);
}


const CRational operator - (const CRational &num1, const CRational &num2)
{
	int numerator = num1.GetNumerator() * num2.GetDenominator() - num2.GetNumerator() * num1.GetDenominator();
	int denominator = num1.GetDenominator() * num2.GetDenominator();
	return CRational(numerator, denominator);
}


CRational& CRational::operator +=(CRational const& rational)
{
	m_numerator = m_numerator * rational.m_denominator + rational.m_numerator * m_denominator;
	m_denominator *= rational.m_denominator;
	Normalize();
	return *this;
}

CRational& CRational::operator -=(CRational const& rational)
{
	m_numerator = m_numerator * rational.m_denominator - rational.m_numerator * m_denominator;
	m_denominator *= rational.m_denominator;
	Normalize();
	return *this;
}

const CRational operator *(const CRational &num1, const CRational &num2)
{
	return CRational(num1.GetNumerator() * num2.GetNumerator(), num1.GetDenominator()  * num2.GetDenominator());
}

const CRational operator /(const CRational &num1, const CRational &num2)
{
	return CRational(num1.GetNumerator() * num2.GetDenominator(), num2.GetNumerator() *num1.GetDenominator());
}

CRational& CRational::operator *=(CRational const& rational)
{
	m_numerator *= rational.m_numerator;
	m_denominator *= rational.m_denominator;
	Normalize();
	return *this;
}


CRational& CRational::operator /=(CRational const& rational)
{
	m_numerator *= rational.m_denominator;
	m_denominator *= rational.m_numerator;
	Normalize();
	return *this;
}


bool operator == (const CRational &num1, const CRational &num2)
{
	return (num1.GetNumerator() == num2.GetNumerator() && num1.GetDenominator() == num2.GetDenominator());
}

bool operator != (const CRational &num1, const CRational &num2)
{
	return !(num1 == num2);
}

bool operator <(const CRational &num1, const CRational &num2)
{
	return (num1.GetNumerator() * num2.GetDenominator() < num2.GetNumerator() * num1.GetDenominator());
}

bool operator >=(const CRational &num1, const CRational &num2)
{
	return !(num1 < num2);
}

bool operator >(const CRational &num1, const CRational &num2)
{
	return (num1.GetNumerator() * num2.GetDenominator() > num2.GetNumerator() * num1.GetDenominator());
}

bool operator <=(const CRational &num1, const CRational &num2)
{
	return !(num1 > num2);
}

std::ostream& operator << (std::ostream &stream, const CRational &num)
{
	return stream << num.GetNumerator() << "/" << num.GetDenominator();
}

std::istream & operator>>(std::istream & stream, CRational & rational)
{
	std::streamoff pos = stream.tellg();

	int numerator = 0;
	int denominator = 0;
	if ((stream >> numerator) && (stream.get() == '/') && (stream >> denominator))
	{
		rational = CRational(numerator, denominator);
		return stream;
	}

	stream.seekg(pos);
	stream.setstate(std::ios_base::failbit | stream.rdstate());
	return stream;
}

std::pair<int, CRational> CRational::ToCompoundFraction() const
{ 
	CRational number(*this);
	int unit = number.m_numerator / number.m_denominator;
	number.m_numerator -= unit * number.m_denominator;
	return std::pair<int, CRational>(unit, number);
}