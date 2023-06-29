
#include <iostream>

#include "TestingFunctions.h"


int main()
{
	int numbers[5] = { 1,2,3,4,5 };
	
	testSingleLinkedList<5>(numbers);
	
	std::cout << "//////////////////////////////////////////////" << std::endl;
	std::cout << "Now testing the Proffesional Employee classes" << std::endl;
	std::cout << "//////////////////////////////////////////////\n" << std::endl;

	ProfEmployee employeeOne("Nicholas", 50000 / 12);
	testingProfClass(employeeOne);
	std::cout << std::endl;

	std::cout << "//////////////////////////////////////////////" << std::endl;
	std::cout << "Now testing the NonProffesional Employee classes" << std::endl;
	std::cout << "//////////////////////////////////////////////\n" << std::endl;

	NonProfEmployee employeeTwo("Mckenzie", 20);
	testingNonProfClass(employeeTwo);

	return 0;
}