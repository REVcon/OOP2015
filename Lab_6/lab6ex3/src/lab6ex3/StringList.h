#pragma once
#include "Record.h"

using namespace std;

class CStringList
{
public:
	CStringList();
	~CStringList();
	shared_ptr<CRecord> GetFirst() const;
	shared_ptr<CRecord> GetLast() const;
	shared_ptr<CRecord> GetNext(const shared_ptr<CRecord> &ptr) const;
	shared_ptr<CRecord> GetPrev(const shared_ptr<CRecord> &ptr) const;
	string GetVal(const shared_ptr<CRecord> &ptr) const;
	void Insert(const string &s, shared_ptr<CRecord> &ptr = shared_ptr<CRecord>());
	void Delete(const shared_ptr<CRecord> elem);

private:
	shared_ptr<CRecord> m_first;
	shared_ptr<CRecord> m_last;
};