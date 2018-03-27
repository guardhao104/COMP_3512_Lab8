#include "FixedList.h"

template<class T, size_t N> FixedList<T, N>::FixedList()
{
	current_size = 0;
}

template<class T, size_t N> FixedList<T, N>::~FixedList()
{
}

//Get function to get element in specified position.
//PARAM		index is the position we want to get element
//PRE		index >= 0
//PRE		index < current size
//POST		NULL
//RETURN	the element or throw an unsigned int as exception
template<class T, size_t N> const T& FixedList<T, N>::get(unsigned int index) const
{
	if (index >= current_size)
		throw index;
	return list[index];
}

//Overload operator[] to get element in specified position.
//PARAM		index is the position we want to get element
//PRE		index >= 0
//PRE		index < current size
//POST		NULL
//RETURN	the element or throw an unsigned int as exception
template<class T, size_t N> T& FixedList<T, N>::operator[](unsigned int index)
{
	if (index >= current_size)
		throw index;
	return list[index];
}

//This function will search and find the first occurpt of element and return the index.
//PARAM		t is the element we want to find
//PRE		NULL
//POST		NULL
//RETURN	the index of the first same element or -1 if we cannot find
template<class T, size_t N> int FixedList<T, N>::getFirstIndex(const T& t) const
{
	for (int i = 0; i < current_size; ++i)
	{
		if (list[i] == t)
			return i;
	}
	return -1;
}

//Get the current size of this list.
//PRE		NULL
//POST		NULL
//RETURN	the current size
template<class T, size_t N> size_t FixedList<T, N>::size() const
{
	return current_size;
}

//Get the capacity of this list.
//PRE		NULL
//POST		NULL
//RETURN	the capacity
template<class T, size_t N> size_t FixedList<T, N>::capacity() const
{
	return N;
}

//Add an element into the list after alll other elements.
//PARAM		t is the element we want to put inside
//PRE		the list should have enough room
//POST		if successful, an element wil be put inside and size will change
//RETURN	the result if successful
template<class T, size_t N> bool FixedList<T, N>::add(const T& t)
{
	if (current_size == N)
		return false;
	list[current_size++] = t;
	return true;
}

//Remove an element from the list if exist and then return this element.
//PARAM		t is the element we want to remove
//PRE		there is a t inside the list
//POST		if successful, the element will be removed from list
//RETURN	the element we removed or throw a t as exception
template<class T, size_t N> T FixedList<T, N>::remove(const T& t)
{
	for (int i = 0; i < current_size; ++i)
	{
		if (list[i] == t)
		{
			T temp = list[i];
			for (int j = i + 1; j < current_size; ++j)
			{
				list[j - 1] = list[j];
			}
			--current_size;
			return temp;
		}
	}
	throw t;
	return t;
}