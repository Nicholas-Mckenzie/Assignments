
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <exception>
#include <time.h>

#include "Application.h"

void AnotherTest()
{
	int temp[10] = { 0 };
	std::cout << "test" << std::endl;
}

void test()
{
	IntArray temp;
	temp.printArray();
}


int main()
{

	Application app;
	app.run();	


	return 0;
}