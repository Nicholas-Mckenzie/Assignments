
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <exception>
#include <time.h>

// Populates the Arrays text file with a randomly generated 10 element arrays
void writeFile()
{
	std::ofstream file;
	file.open("Arrays.txt", std::ofstream::out | std::ofstream::trunc);

	for (int i = 0; i < 10; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			file << std::rand() % 100 << " ";
		}
		file << std::endl;
	}

	file.close();
}


int main()
{
	// Generates a seed for std::rand()
	std::srand(time(NULL));


	std::string input;

	while (true)
	{
		break;

		std::cout << "Type command" << std::endl;
		std::cin >> input;

		if (input == "gen")
		{	
			writeFile();
		}
		else if (input == "break")
		{
			break;
		}
		else
		{
			std::cout << "Wrong command" << std::endl;
		}
	}


	return 0;
}