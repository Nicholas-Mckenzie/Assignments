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
};

class IntArray
{
public:

	// Returns the size of the array
	int size() const;

	// Checks if given number exist in array
	// Returns index if true
	// Returns -1 if false
	int intExist(int number);

	// Modifies the value of the given index
	Values modifyValue(int value, int index);

	// Adds an integer to the end of the array
	void addInt(int number);

	// Replaces data at the given index with 0 and returns the old data
	int remove(int index);

	// Prints all the values of the array
	void printArray();

	// sets new Array
	void setArray(int newArray[10]);

	// Allows the user to use the index operator on the object
	int operator[](unsigned int index);

	
	// Constructor
	IntArray(int array[10]);

	
private:

	int m_array[10] = {0};
	int m_size;

};