
#include "Application.h"


void Application::run()
{
	init();

	while (true)
	{
		std::cout << "\nHere are the commands: \n" << std::endl;
		std::cout << "Enter \"1\" to generate new arrays" << std::endl;
		std::cout << "Enter \"2\" to select an Array" << std::endl;
		printCommonCommands();
		std::cout << "\nEnter Command: ";


		std::string input;
		std::cin >> input;

		// Command to generate new Arrays
		if (input == "1")
		{
			generateArrays();

			std::cout << "\n--------------------------------------------" << std::endl;
			std::cout << "\nArrays Generated\n" << std::endl;
			printArrays();
			std::cout << "\n--------------------------------------------" << std::endl;
		}

		// Command to select an array
		else if (input == "2")
		{
			if (selectArray() == -1) 
			{	
				quit();
				return; 
			}
		}

		// Prints current Arrays to console
		else if (input == "arrays")
		{
			std::cout << "\n--------------------------------------------" << std::endl;
			printArrays();
			std::cout << "\n--------------------------------------------\n" << std::endl;
		}
		else if (input == "start" || input == "back")
		{
			std::cout << std::endl;
			continue;
		}
		// Command to quit the program
		else if (input == "quit")
		{
			quit();
			return;
		}
		else
		{
			std::cout << "\nInvalid input try again" << std::endl;
			std::cout << "-------------------------" << std::endl;
		}

	}
}

void Application::printArrays() const
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "#" << i+1 << ": ";
		arrays[i].printArray();
	}
}

void Application::init()
{
	// Generates a seed for std::rand()
	std::srand(time(NULL));

	generateArrays();

	std::cout << "\nWelcome to my program" << std::endl;
	std::cout << "here are your first set of Arrays" << std::endl;

	std::cout << "\n////////////////////////////////////////////////" << std::endl;
	printArrays();
	std::cout << "////////////////////////////////////////////////\n" << std::endl;
}

void Application::generateArrays()
{
	std::ofstream file;
	file.open("Arrays.txt", std::ofstream::out | std::ofstream::trunc);

	int temp[10] = { 0 };
	int randNum = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			randNum = std::rand() % numRange;
			file << randNum << " ";
			temp[j] = randNum;
		}
		file << std::endl;
		arrays[i].setArray(temp);
	}

	file.close();
}

int Application::selectArray()
{
	std::cout << "\n--------------------------------------------\n" << std::endl;
	std::cout << "Here are the current arrays\n" << std::endl;
	printArrays();

	std::string input;
	int number = 0;
	int temp = 0;
	int commandsCheck = 0;

	while (true)
	{
		std::cout << "\nEnter a number to select an array\n" << std::endl;
		std::cout << "Enter: ";


		std::cin >> input;
		commandsCheck = checkInputForCommands(input);

		if (commandsCheck != 3)
		{
			if (commandsCheck == 2) { continue; }

			return commandsCheck;
		}
		else
		{
			try
			{
				number = std::stoi(input);
			}
			catch (std::invalid_argument& e)
			{
				std::cout << "\nInvalid input try again\n" << std::endl;
				continue;
			}

			if (number >= 1 && number <= 10)
			{
				temp = arrayCommandsPrompt(arrays[number - 1]);

				if (temp == -1 || temp == 1)
				{
					return temp;
				}

				continue;
			}
			else
			{
				std::cout << "\nPlease enter a number between 1-10" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}
		}
	}

	return false;
}

int Application::arrayCommandsPrompt(IntArray& array)
{
	std::cout << "\n--------------------------------------------\n" << std::endl;
	std::cout << "Here is the array you selected\n" << std::endl;
	
	std::string input;
	int number = 0;
	int temp;

	while (true)
	{
		std::cout << "Selected Array: "; 
		array.printArray();
		std::cout << "\nHere are the commands:\n" << std::endl;
		std::cout << "Enter \"1\" to check if a number exist" << std::endl;
		std::cout << "Enter \"2\" to modify an element" << std::endl;
		std::cout << "Enter \"3\" to append a number" << std::endl;
		std::cout << "Enter \"4\" to delete an element" << std::endl;

		std::cout << "\nEnter: ";
		std::cin >> input;
		temp = checkInputForCommands(input);

		if (temp != 3)
		{
			if (temp == 2) { continue; }

			return temp;
		}
		else
		{
			try
			{
				number = std::stoi(input);
			}
			catch (std::invalid_argument& e)
			{
				std::cout << "\nInvalid Input" << std::endl;
				std::cout << "--------------------\n" << std::endl;
			}

			if (number >= 1 && number <= 4)
			{
				int temp = arrayCommands(array, number);
				if (temp == -1 || temp == 1)
				{
					return temp;
				}
			}
			else
			{
				std::cout << "\nPick a number between 1-4\n" << std::endl;
			}
		}
	}

	return -1;
}

int Application::arrayCommands(IntArray& array, int command)
{
	std::string input;
	int commonCommand = -3;

	while (true)
	{
		std::cout << "\n-----------------------------------------\n" << std::endl;
		std::cout << "Enter \"current\" to print selected array\n" << std::endl;


		// Starting prompt for users given command
		if (command == 1)
		{
			std::cout << "Enter Number to check: ";
		}
		else if (command == 2)
		{
			std::cout << "Enter index to modify: ";
		}
		else if (command == 3)
		{
			if (array.size() == array.capacity())
			{
				std::cout << "\nArray is full\n" << std::endl;
				std::cout << "-------------------------\n" << std::endl;
				return 0;
			}

			std::cout << "Enter number to add: ";
		}
		else if (command == 4)
		{
			std::cout << "Enter index to delete: ";
		}

		std::cin >> input;
		commonCommand = checkInputForCommands(input);

		if (input == "current")
		{
			std::cout << "\nSelected Array: ";
			array.printArray();
			continue;
		}

		if (commonCommand != 3)
		{
			if (commonCommand == 2) { continue; }
			return commonCommand;
		}


		// Calls the appropiate method on the array
		if (command == 1)
		{
			command1(array, input);
		}
		else if (command == 2)
		{
			int temp = 0;
			
			try
			{
				temp = command2(array, input);
			}
			catch (std::out_of_range& e)
			{
				std::cout << "\nInvalid Index" << std::endl;
				continue;
			}


			if (temp != 3)
			{
				if (temp == 2) { continue; }
				return temp;
			}
		}
		else if (command == 3)
		{
			command3(array, input);
			if (array.size() == array.capacity()) 
			{ 
				std::cout << "\nArray is now full\n" << std::endl;
				std::cout << "-------------------------\n" << std::endl;
				return 0;
			}
		}
		else if (command == 4)
		{
			command4(array, input);
		}
	}

	return 0;
}

void Application::command1(IntArray& array, std::string& input)
{
	int number = 0;
	int exist = -1;

	try
	{
		number = std::stoi(input);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "\nInvalid input\n" << std::endl;
		return;
	}

	exist = array.intExist(number);

	std::cout << std::endl;
	if (exist == -1)
	{
		std::cout << "Number not in array" << std::endl;
	}
	else
	{
		std::cout << "Number exist at index " << exist << std::endl;
	}
}

int Application::command2(IntArray& array, std::string& input)
{
	int index = -1;
	Values values;
	std::string strNewValue;
	int intNewValue;
	int temp = 3;

	try
	{
		index = std::stoi(input);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "\nInvalid input" << std::endl;
		return 3;
	}

	if (index >= array.size())
	{
		throw std::out_of_range("Index out of bounds");
	}

	while (true)
	{
		std::cout << "\nEnter a number: ";
		std::cin >> strNewValue;
		temp = checkInputForCommands(input);

		if (temp != 3)
		{
			if (temp == 2) { continue; }
			return temp;
		}

		if (strNewValue == "current")
		{
			std::cout << "---------------------" << std::endl;
			std::cout << "\nSelected Array: ";
			array.printArray();
			std::cout << "---------------------" << std::endl;
			continue;
		}

		try 
		{
			intNewValue = std::stoi(strNewValue);
		}
		catch (std::invalid_argument& e)
		{
			std::cout << "\nEnter a valid number" << std::endl;
			std::cout << "---------------------" << std::endl;
			continue;
		}

		values = array.modifyValue(intNewValue, index);
		std::cout << "\n---------------------\n" << std::endl;

		return 0;
	}


	return 3;
}

void Application::command3(IntArray& array, std::string& input)
{
	int number = 0;

	try
	{
		number = std::stoi(input);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "\nInvalid input\n" << std::endl;
		return;
	}

	try
	{
		array.addInt(number);
	}
	catch (std::length_error& e)
	{
		std::cout << e.what() << "\n" << std::endl;
	}
}

void Application::command4(IntArray& array, std::string& input)
{
	int index = -1;
	int oldValue = -1;

	if (array.size() == 0)
	{
		std::cout << "\nArray is empty" << std::endl;
		return;
	}

	try
	{
		index = std::stoi(input);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "\nInvalid input\n" << std::endl;
		return;
	}

	try
	{
		oldValue = array.remove(index);
	}
	catch (std::out_of_range& e)
	{
		std::cout << "\nEnter a valid index" << std::endl;
		return;
	}

	std::cout << "\nDeleted old value of " << oldValue << std::endl;
}

void Application::printCommonCommands() const
{
	std::cout << "Enter \"start\" at anytime to go to the start" << std::endl;
	std::cout << "Enter \"quit\" at anytime to quit the program" << std::endl;
	std::cout << "Enter \"back\" at anytime to go to a previous prompt" << std::endl;
	std::cout << "Enter \"arrays\" at anytime to print current arrays" << std::endl;
}

int Application::checkInputForCommands(std::string& input) const
{
	if (input == "quit") 
	{ 
		quit();
		return -1;
	}
	else if (input == "back") { return 0; }
	else if (input == "start") { return 1; }
	else if (input == "arrays")
	{ 
		std::cout << "\n--------------------------------------------" << std::endl;
		printArrays();
		std::cout << "\n--------------------------------------------" << std::endl;
		return 2;
	}
	
	return 3;
}


void Application::quit() const
{
	std::cout << "\nQuiting program" << std::endl;
}
