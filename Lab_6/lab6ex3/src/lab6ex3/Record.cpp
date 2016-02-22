#include "stdafx.h"
#include "Record.h"

using namespace std;

CRecord::CRecord(const string &s)
	: m_value(s)
	, m_prev(shared_ptr<CRecord>())
	, m_next(shared_ptr<CRecord>())
{	
}

CRecord::~CRecord()
{
}

shared_ptr<CRecord> CRecord::GetPrev() const
{
	return m_prev;
}

shared_ptr<CRecord> CRecord::GetNext() const
{
	return m_next;
}

string CRecord::GetValue() const
{
	return m_value;
}

void CRecord::SetPrev(const shared_ptr<CRecord> &prev)
{
	m_prev  = prev;
}

void CRecord::SetNext(const shared_ptr<CRecord> &next)
{
	m_next = next;
}