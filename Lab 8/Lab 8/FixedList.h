#pragma once

template<class T, size_t N>
class FixedList
{
public:
	FixedVector();
	~FixedVector();
	const T& get(unsigned int index) const;
	T& operator[](unsigned int index);
	int getFirstIndex(const T& t) const;
	size_t size() const;
	size_t capacity() const;
	bool add(const T& t);
	T remove(const T& t);
private:
	T * list;
	size_t size;
};

template<class T, size_t N> FixedList::FixedVector()
{
	size = 0;
	list = new T[N];
}

template<class T, size_t N> FixedList::~FixedVector()
{
	delete[] list;
}

template<class T, size_t N> const T& FixedList::get(unsigned int index) const
{
	if (index >= size)
		throw index;
	return list[index];
}

template<class T, size_t N> T& FixedList::operator[](unsigned int index)
{
	if (index >= size)
		throw index;
	return list[index];
}

template<class T, size_t N> int FixedList::getFirstIndex(const T& t) const
{
	for (int i = 0; i < size; ++i)
	{
		if (list[i] == t)
			return i;
	}
	return -1;
}

template<class T, size_t N> size_t FixedList::size() const
{
	return size;
}

template<class T, size_t N> size_t FixedList::capacity() const
{
	return N;
}

template<class T, size_t N> bool FixedList::add(const T& t)
{
	if (size == N)
		return false;
	list[size++] = t;
	return true;
}

template<class T, size_t N> T FixedList::remove(const T& t)
{
	for (int i = 0; i < size; ++i)
	{
		if (list[i] == t)
		{
			T temp = list[i];
			for (int j = i + 1; j < size; ++j)
			{
				list[j - 1] = list[j];
			}
			list[--size] = null;
			return temp;
		}
	}
	return null;
}