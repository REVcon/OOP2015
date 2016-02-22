#pragma once
#include "Node.h"

using namespace std;

template<typename T>

class CMySet
{
public:
	CMySet()
	{
	}

	CMySet(const CMySet<T> &other)
	{
		if (other.m_first)
		{
			auto curPtr = other.m_first;
			auto prevPtr = make_shared<CNode<T>>(curPtr->GetValue());
			m_first = prevPtr;
			while (curPtr)
			{
				auto newPtr = make_shared<CNode<T>>(curPtr->GetValue());
				prevPtr->SetNext(newPtr);
				prevPtr = newPtr;
				curPtr = curPtr->GetNext();
			}
			m_size = other.m_size;
		}	
		else
		{
			Clear();
		}
	}

	CMySet<T> &operator = (const CMySet<T> &other)
	{
		if (addressof(other) != this)
		{
			CMySet<T> tmpCopy(other);
			m_first = move(tmpCopy.m_first);
			m_size = move(tmpCopy.m_size);
		}
		return *this;
	}

	size_t GetSize() const
	{
		return m_size;
	}

	bool IsEmpty() const
	{
		return m_size == 0;
	}

	bool Contains(const T &elem) const
	{
		auto curPtr = m_first;
		while (curPtr != shared_ptr<CNode<T>>() && curPtr->GetValue() <= elem)
		{
			if (curPtr->GetValue() == elem)
			{
				return true;
			}
			curPtr = curPtr->GetNext();
		}
		return false;
	}

	bool ContainsSubset(const CMySet<T> &other) const
	{
		auto curPtr = other.m_first;
		while (curPtr)
		{
			if (!Contains(curPtr->GetValue()))
			{
				return false;
			}
			curPtr = curPtr->GetNext();
		}
		return true;
	}

	bool Equal(const CMySet<T> &other) const
	{
		return ContainsSubset(other) && other.ContainsSubset(*this);
	}

	void Add(const T &newElem)
	{
		if (!Contains(newElem))
		{
			if (!m_first)
			{
				m_first = make_shared<CNode<T>>(newElem);
				m_size++;
				return;
			}
			if (m_first->GetValue() > newElem)
			{
				m_first = make_shared<CNode<T>>(newElem, std::move(m_first));
				m_size++;
				return;
			}
			auto curPtr = m_first;
			bool isNextNoNull = true;
			while (isNextNoNull && curPtr->GetValue() < newElem)
			{
				auto next = curPtr->GetNext();
				if (!next)
				{
					isNextNoNull = false;
				}
				else
				{
					curPtr = next;
				}				
			}
			auto ptr = make_shared<CNode<T>>(newElem);
			auto next = curPtr->GetNext();
			curPtr->SetNext(ptr);
			ptr->SetNext(next);
			m_size++;
		}
	}

	T GetElement(size_t index)
	{
		if (index > m_size)
		{
			throw out_of_range("Given index more than size of set");
		}
		auto curPtr = m_first;
		while (index > 0)
		{
			curPtr = curPtr->GetNext();
			index--;
		}
		return curPtr->GetValue();
	}

	void Clear()
	{
		m_first = shared_ptr<CNode<T>>();
		m_size = 0;
	}

	CMySet<T> Union(const CMySet<T> &other) const
	{
		CMySet<T> result = other;
		auto curPtr = m_first;
		while (curPtr)
		{
			if (!other.Contains(curPtr->GetValue()))
			{
				result.Add(curPtr->GetValue());
			}
			curPtr = curPtr->GetNext();
		}
		return result;
	}

	CMySet<T> Intersection(const CMySet<T> &other) const
	{
		CMySet<T> result;
		auto curPtr = m_first;
		while (curPtr)
		{
			if (other.Contains(curPtr->GetValue()))
			{
				result.Add(curPtr->GetValue());
			}
			curPtr = curPtr->GetNext();
		}
		return result;
	}

	CMySet<T> Difference(const CMySet<T> &other) const
	{
		CMySet<T> result;
		auto curPtr = m_first;
		while (curPtr)
		{
			if (!other.Contains(curPtr->GetValue()))
			{
				result.Add(curPtr->GetValue());
			}
			curPtr = curPtr->GetNext();
		}
		return result;
	}

	CMySet<T> SymmetricDifference(const CMySet<T> &other) const
	{
		CMySet<T> firstDifference = Difference(other);
		CMySet<T> secondDifference = other.Difference(*this);
		CMySet<T> result = firstDifference.Union(secondDifference);
		return result;
	}

private:
	std::shared_ptr<CNode<T>> m_first;
	size_t m_size;
};