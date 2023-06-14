
#include "IntArray.h"


int IntArray::size() const
{
	return m_size;
}

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

	return Values(m_array[index], value);
}



int IntArray::remove(int index)
{
	if (index >= m_size)
	{
		throw std::out_of_range("index out of range");
	}

	int oldValue = m_array[index];
	m_array[index] = 0;

	return oldValue;
}

void IntArray::printArray()
{
	for (int i = 0; i < m_size; i++)
	{
		std::cout << m_array[i] << ", ";
	}
	std::cout << std::endl;
}

void IntArray::setArray(int newArray[10])
{
	for (int i = 0; i < 10; i++)
	{
		m_array[i] = newArray[i];
	}
}

IntArray::IntArray(int array[10])
	: m_size(10)
{
	setArray(array);
}

int IntArray::operator[] (unsigned int index)
{
	return m_array[index];
}



