#pragma once
#include <memory>

template <typename T>
class CNode
{
public:
	CNode(T value = T(), std::shared_ptr<CNode<T>> ptr = std::shared_ptr<CNode<T>>())
		: m_value(move(value))
		, m_next(ptr)
	{
	}

	std::shared_ptr<CNode<T>> GetNext() const
	{
		return m_next;
	}

	T GetValue() const
	{
		return m_value;
	}

	void SetNext(const std::shared_ptr<CNode<T>> &next)
	{
		m_next = next;
	}

private:
	T m_value;
	std::shared_ptr<CNode<T>> m_next;
};