#include "stdafx.h"
#include "StringList.h"

using namespace std;

CStringList::CStringList()
	:m_first()
	, m_last()
{
}


CStringList::~CStringList()
{
	auto ptr = m_first;
	while (ptr != shared_ptr<CRecord>())
	{
		auto temp = ptr->GetNext();
		ptr->SetNext(shared_ptr<CRecord>());
		ptr->SetPrev(shared_ptr<CRecord>());
		ptr = temp;
	}
	ptr.reset();
	m_first.reset();
	m_last.reset();
}

shared_ptr<CRecord> CStringList::GetFirst() const
{
	return m_first;
}

shared_ptr<CRecord> CStringList::GetLast() const
{
	return m_last;
}

shared_ptr<CRecord> CStringList::GetNext(const shared_ptr<CRecord> &ptr) const
{
	return ptr->GetNext();
}

shared_ptr<CRecord> CStringList::GetPrev(const shared_ptr<CRecord> &ptr) const
{
	return ptr->GetPrev();
}

string CStringList::GetVal(const shared_ptr<CRecord> &ptr) const
{
	return ptr->GetValue();
}

void CStringList::Insert(string const&s, shared_ptr<CRecord> &ptr)
{
	auto newPtr = make_shared<CRecord>(s);
	if (!m_first)
	{
		m_first = newPtr;
		m_last = newPtr;
	}
	else if (ptr)
	{
		newPtr->SetPrev(ptr);
		auto it = ptr->GetNext();
		newPtr->SetNext(it);
		if (it)
		{
			it->SetPrev(newPtr);
		}
		ptr->SetNext(newPtr);
		if (m_last == ptr)
		{
			m_last = newPtr;
		}
	}
	else
	{
		newPtr->SetPrev(shared_ptr<CRecord>());
		newPtr->SetNext(m_first);
		m_first->SetPrev(newPtr);
		m_first = newPtr;
	}	
}

void CStringList::Delete(const shared_ptr<CRecord> elem)
{
	auto it = elem->GetNext();
	if (it)
	{
		elem->GetNext()->SetPrev(elem->GetPrev());
	}
	else
	{
		m_last = elem->GetPrev();
	}
	it = elem->GetPrev();
	if (it)
	{
		elem->GetPrev()->SetNext(elem->GetNext());
	}
	else
	{
		m_first = elem->GetNext();
	}
}

