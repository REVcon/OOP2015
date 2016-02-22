#include "stdafx.h"
#include "MyString.h"

using namespace std;

void CMyString::ReallocMemory(size_t newSize)
{
	char *tmp = new char[newSize + 1];
	size_t size = (newSize > m_length) ? m_length : newSize;
	memcpy(tmp, m_data, size);
	delete[] m_data;
	m_data = tmp;
	m_length = newSize;
	m_data[m_length] = '\0';
}

CMyString::CMyString()
	:m_length(0)
{
	m_data = new char[1];
	m_data[0] = '\0';
}

CMyString::CMyString(const char *pString)
	:CMyString(pString, strlen(pString))
{
}

CMyString::CMyString(const char *pString, unsigned length)
	: m_length(length)
{
	m_data = new char[m_length + 1];
	memcpy(m_data, pString, m_length);
	m_data[m_length] = '\0';
}

CMyString::CMyString(const string &stlString)
	:CMyString(stlString.c_str(), stlString.size())
{	
}

CMyString::CMyString(const CMyString &other)
	:m_length(other.GetLength())
{
	m_data = new char[m_length + 1];
	memcpy(m_data, other.m_data, m_length);
	m_data[m_length] = '\0';
}

CMyString::CMyString(CMyString &&other)
	:m_data(other.m_data)
	, m_length(other.m_length)
{
	other.m_length = 0;
	other.m_data = nullptr;
}

CMyString::~CMyString()
{
	delete[] m_data;
}

unsigned CMyString::GetLength() const
{
	return m_length;
}

const char* CMyString::GetStringData() const
{
	return m_data;
}

CMyString CMyString::SubString(unsigned start, unsigned length) const
{
	if (start >= m_length)
	{
		throw invalid_argument("Index of begin more then length of string");
	}
	return CMyString(GetStringData() + start, min(length, GetLength() - start));
}

void CMyString::Clear()
{
	ReallocMemory(0);
	
}

CMyString& CMyString::operator = (const CMyString &other)
{
	if (addressof(other) != this)
	{
		CMyString tmpCopy(other);
		swap(m_data, tmpCopy.m_data);
		swap(m_length, tmpCopy.m_length);
	}
	return *this;
}

CMyString& CMyString::operator = (CMyString &&other)
{
	if (addressof(other) != this)
	{
		CMyString tmpCopy(move(other));
		swap(m_data, tmpCopy.m_data);
		swap(m_length, tmpCopy.m_length);
	}
	return *this;
}


const char& CMyString::operator[](size_t index) const
{
	if (index >= m_length)
		throw out_of_range("Index is out of range");
	return m_data[index];
}

char& CMyString::operator[](size_t index)
{
	if (index >= m_length)
		throw out_of_range("Index is out of range");
	return m_data[index];
}

CMyString& CMyString::operator += (const CMyString &str)
{
	size_t oldSize = m_length;
	ReallocMemory(m_length + str.m_length);
	memcpy(m_data + oldSize, str.m_data,  str.m_length);
	return *this;
}

const CMyString operator + (const CMyString &str1, const CMyString &str2)
{
	CMyString str;
	str.ReallocMemory(str1.GetLength() + str2.GetLength());
	memcpy(str.m_data, str1.m_data, str1.m_length);
	memcpy(str.m_data + str1.m_length, str2.m_data, str2.m_length);
	return str;
}

bool operator == (const CMyString &str1, const CMyString &str2)
{
	int res = Compare(str1, str2);
	return res == 0;
}

int Compare(const CMyString &str1, const CMyString &str2)
{
	int res = memcmp(str1.GetStringData(), str2.GetStringData(), min(str1.GetLength(), str2.GetLength()));
	if (res == 0)
	{
		if (str1.GetLength() == str2.GetLength())
		{
			return res;
		}
		return str1.GetLength() < str2.GetLength()? -1 : 1 ;
	}
	return res;
}

bool operator != (const CMyString &str1, const CMyString &str2)
{
	int res = Compare(str1, str2);
	return res != 0;
}

bool operator < (const CMyString &str1, const CMyString &str2)
{
	int res = Compare(str1, str2);
	return res < 0;
}

bool operator <= (const CMyString &str1, const CMyString &str2)
{
	return !(str1 > str2);
}

bool operator > (const CMyString &str1, const CMyString &str2)
{
	int res = Compare(str1, str2);
	return res > 0;
}

bool operator >= (const CMyString &str1, const CMyString &str2)
{
	return !(str1  < str2);
}

std::istream& operator>>(std::istream &stream, CMyString &str)
{
	streamoff pos = stream.tellg();
	string tmpStr;
	if (stream >> tmpStr)
	{
		str = tmpStr;
		return stream;
	}
	stream.seekg(pos);
	stream.setstate(ios_base::failbit | stream.rdstate());
	return stream;
}

std::ostream& operator<<(std::ostream &stream, const CMyString &str)
{
	for (size_t i = 0; i < str.GetLength(); ++i)
	{
		stream.put(str[i]);
	}
	return stream;
}

