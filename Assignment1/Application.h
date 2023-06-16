#pragma once

#include "IntArray.h"

#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <exception>

class Application
{
public:
	void run();

	void printArrays() const;


private:

	// Sets up the application 
	void init();

	// Generates 10 new arrays and writes to file
	void generateArrays();

	// Allows users to select which array they would like to give commands to
	// If return value is false quit program
	int selectArray();

	// Allows the user call the 4 functions for assignment 1
	// If return value is -1 quit program
	// If return value is 0 user wants to go to previous prompt
	// If reutnr value is 1 user wants to go to start
	int arrayCommandsPrompt(IntArray& array);

	int arrayCommands(IntArray& array, int number);

	// Checks if integer exist in array
	void command1(IntArray& array, std::string& input);

	// Modifies element in array
	int command2(IntArray& array, std::string& input);

	// Adds integer to end of array
	void command3(IntArray& array, std::string& input);

	// Deletes element in array
	void command4(IntArray& array, std::string& input);

	// Prints the commands that can be used at anytime
	void printCommonCommands() const;

	// Checks for input of "start", "quit", "back", and "arrays"
	// returns -1 for quit, 0 for back, 1 for start, 2 for arrays, and 3 otherwise
	int checkInputForCommands(std::string& input) const;

	// Writes a message to console when quiting program
	void quit() const;


	IntArray arrays[10];
	int numRange = 10;

};