#pragma once

#include <iostream>
#include <exception>

struct Values
{
	int oldValue;
	int newValue;

	Values(int oldVal, int newVal)
		: oldValue(oldVal), newValue(newVal)
	{}

	Values()
		:oldValue(0), newValue(0)
	{
	}
};

class IntArray
{
public:

	// Checks if given number exist in array
	// Returns index of the first instance of the number if true
	// Returns -1 if false
	int intExist(int number);

	// Modifies the value of the given index
	Values modifyValue(int value, int index);

	// Adds an integer to the end of the array
	void addInt(int number);

	// Deletes the data shifting all values after index back 1
	// Returns old value
	int remove(int index);


	// -------------------------------------------- //
	// ----- Below are non-assignment methods ----- //
	// -------------------------------------------- //


	// Returns the size of the array
	int size() const;

	// Returns the max size of the array
	int capacity() const;

	// Prints all the values of the array
	void printArray() const;

	// sets new Array
	void setArray(int newArray[10]);

	// Allows the user to use the index operator on the object
	int operator[](unsigned int index);

	
	// Default Constructor
	IntArray();

	// Constructor
	IntArray(int array[10]);

	
private:

	int m_array[15] = {0};
	int m_size;
	int m_capacity;

};