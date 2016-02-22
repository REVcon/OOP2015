#pragma once

class CMyString final
{
public:
	CMyString();
	CMyString(const char *pString);
	CMyString(const char *pString, unsigned length);
	CMyString(const CMyString &other);
	CMyString(CMyString &&other);
	CMyString(const std::string &stlString);

	~CMyString();

	size_t GetLength() const;
	const char* GetStringData() const;
	CMyString SubString(unsigned start, unsigned length = UINT_MAX) const;

	void Clear();

	CMyString& operator=(const CMyString &str);
	CMyString& operator=(CMyString &&str);

	CMyString& operator+=(const CMyString &str);

	const char& operator[](size_t index) const;
	char& operator[](size_t index);
	friend const CMyString operator + (const CMyString &str1, const CMyString &str2);

private:	
	void ReallocMemory(size_t newSize);
	char* m_data;
	size_t m_length;
};


bool operator==(const CMyString &str1, const CMyString &str2);
bool operator!=(const CMyString &str1, const CMyString &str2);

bool operator<(const CMyString &str1, const CMyString &str2);
bool operator<=(const CMyString &str1, const CMyString &str2);
bool operator>(const CMyString &str1, const CMyString &str2);
bool operator>=(const CMyString &str1, const CMyString &str2);

std::istream& operator>>(std::istream &stream, CMyString &str);
std::ostream& operator<<(std::ostream &stream, const CMyString &str);
int Compare(const CMyString &str1, const CMyString &str2);



