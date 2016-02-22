#pragma once

#include <memory>

template <typename T>
class CMyArray
{
public:

	CMyArray()
	{
	}

	CMyArray(CMyArray const& other)
	{
		size_t size = other.GetSize();
		auto newItems = std::make_unique<T[]>(size);
		for (size_t i = 0; i < size; ++i)
		{
			newItems[i] = other[i];
		}
		m_items = std::move(newItems);
		m_size = size;
	}

	~CMyArray()
	{
	}

	bool IsEmpty()const
	{
		return m_size == 0;
	}

	size_t GetSize()const
	{
		return m_size;
	}

	T const & operator [] (size_t index)const
	{
		if (index >= m_size)
			throw std::out_of_range("item index is out of range");
		return m_items[index];
	}

	T & operator [] (size_t index)
	{
		if (index >= m_size)
			throw std::out_of_range("item index is out of range");
		return m_items[index];
	}

	void Add(T const & item)
	{
		auto newItems = std::make_unique<T[]>(m_size + 1);
		for (size_t i = 0; i < m_size; ++i)
		{
			newItems[i] = m_items[i];
		}
		newItems[m_size] = item;
		m_items = std::move(newItems);
		++m_size;
	}

	void Resize(size_t newSize)
	{
		auto newItems = std::make_unique<T[]>(newSize);
		size_t oldSize = m_size;
		size_t i = 0;
		while (newSize > i)
		{
			if (oldSize > 0)
			{
				newItems[i] = m_items[i];
				oldSize -= 1;
			}
			else
			{
				newItems[i] = T();
			}
			++i;
		}
		m_items = std::move(newItems);
		m_size = newSize;
	}

	void Clear()
	{
		m_items.reset();
		m_size = 0;
	}

	CMyArray& operator = (CMyArray const& other)
	{
		if (addressof(other) != this)
		{
			CMyArray tmp(other);
			m_items = move(tmp.m_items);
			m_size = tmp.m_size;
		}
		return *this;
	}

private:
	std::unique_ptr<T[]> m_items;
	size_t m_size;
};

