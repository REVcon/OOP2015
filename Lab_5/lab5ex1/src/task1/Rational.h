#pragma once


/*
Класс, моделирующий рациональное число
*/
class CRational final
{
public:
	CRational(int numerator = 0, int denominator = 1);

	// Возвращает числитель
	int GetNumerator() const;

	// Возвращает знаменатель
	int GetDenominator() const;

	double ToDouble() const;
	
	CRational const operator +() const;

	CRational const operator -() const;	
	
	CRational& operator +=(CRational const& rational);
	
	CRational& operator -=(CRational const& rational);

	CRational& operator *=(CRational const& rational);

	CRational& operator /=(CRational const& rational);
	
	std::pair<int, CRational> ToCompoundFraction() const;
private:
	int m_numerator;
	int m_denominator;

	// Нормализует рациональное число
	void Normalize();
};

// Вычисляет наибольший общий знаменатель чисел a и b
unsigned GCD(unsigned a, unsigned b);

const CRational operator + (const CRational &num1, const CRational &num2);

const CRational operator - (const CRational &num1, const CRational &num2);

const CRational operator * (const CRational &num1, const CRational &num2);

const CRational operator /(const CRational &num1, const CRational &num2);

bool operator == (const CRational &num1, const CRational &num2);

bool operator != (const CRational &num1, const CRational &num2);

bool operator <(const CRational &num1, const CRational &num2);

bool operator >=(const CRational &num1, const CRational &num2);

bool operator >(const CRational &num1, const CRational &num2);

bool operator <=(const CRational &num1, const CRational &num2);

std::ostream& operator << (std::ostream &stream, const CRational &num);

std::istream & operator>>(std::istream & stream, CRational & rational);