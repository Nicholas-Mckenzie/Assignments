
#include "IntArray.h"


int IntArray::intExist(int number)
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_array[i] == number)
			return i;
	}

	return -1;
}

Values IntArray::modifyValue(int value, int index)
{
	if (index >= m_size)
	{
		throw std::out_of_range("index out of range");
	}

	Values values(m_array[index], value);
	m_array[index] = value;

	return values;
}

void IntArray::addInt(int number)
{
	if (m_size >= m_capacity)
	{
		throw std::length_error("Array is at max capacity");
	}

	m_array[m_size] = number;
	m_size++;
}

int IntArray::remove(int index)
{
	if (index >= m_size || index < 0)
	{
		throw std::out_of_range("index out of range");
	}

	int oldValue = m_array[index];

	for (int i = index; i < m_size - 1; i++)
	{
		m_array[i] = m_array[i + 1];
	}
	m_size--;

	return oldValue;
}

int IntArray::size() const
{
	return m_size;
}

int IntArray::capacity() const
{
	return m_capacity;
}

void IntArray::printArray() const
{
	if (m_size == 0)
	{
		std::cout << "Array is empty" << std::endl;
		return;
	}

	std::cout << "[";
	for (int i = 0; i < m_size-1; i++)
	{
		std::cout << m_array[i] << ", ";
	}
	std::cout << m_array[m_size - 1];
	std::cout << "]";

	std::cout << " | Array size = " << m_size << std::endl;
}

void IntArray::setArray(int newArray[10])
{
	for (int i = 0; i < 10; i++)
	{
		m_array[i] = newArray[i];
	}
	m_size = 10;
}

IntArray::IntArray(int array[10])
	: m_size(10), m_capacity(15)
{
	setArray(array);
}

IntArray::IntArray()
	: m_size(0), m_capacity(15)
{
}

int IntArray::operator[] (unsigned int index)
{
	return m_array[index];
}


