#pragma once

#include "SingleLinkedList.h"
#include "Employee.h"
#include "ProfEmployee.h"
#include "NonProfEmployee.h"



template<size_t n>
void testSingleLinkedList(int array[n])
{
	SingleLinkedList<int> list(array, n);

	std::cout << "Current List: ";
	list.printList();
	std::cout << std::endl;

	// Testing the push functions
	list.pushFront(10);
	list.pushBack(11);
	std::cout << "List after pushes: ";
	list.printList();
	std::cout << std::endl;

	// Testing the pop_front function
	list.popFront();
	std::cout << "List after pops front: ";
	list.printList();
	std::cout << std::endl;

	// Testing the pop_back function
	list.popBack();
	std::cout << "List after pops back: ";
	list.printList();
	std::cout << std::endl;

	// Testing the front and back functions
	std::cout << "printing first item: " << list.front() << std::endl;
	std::cout << "printing last item: " << list.back() << std::endl;
	std::cout << std::endl;

	// Testing the empty function
	std::cout << "Checking if list is empty" << std::endl;
	if (list.empty())
		std::cout << "List is empty" << std::endl;
	else
		std::cout << "List is NOT empty" << std::endl;
	std::cout << std::endl;

	// Testing the insert function
	std::cout << "Current List: ";
	list.printList();
	std::cout << "Inserting 20 at 2 and 30 beyond end" << std::endl;
	list.insert(20, 2);
	list.insert(30, 100);
	list.printList();
	std::cout << std::endl;

	// Testing the remove function
	std::cout << "Removing element at index 1" << std::endl;
	list.remove(1);
	list.printList();
	std::cout << std::endl;

	// Testing the find function
	std::cout << "Looking for 5 in list . . ." << std::endl;
	std::cout << "Found in list at index: " << list.find(5) << std::endl;
	std::cout << std::endl;
}


void testingProfClass(ProfEmployee profOne)
{
	profOne.printMainInfo();

	std::cout << "----------------------------" << std::endl;
	std::cout << "Incrementing absences by 2" << std::endl;
	std::cout << "----------------------------" << std::endl;
	profOne.incrementAbsence();
	profOne.incrementAbsence();

	profOne.printMainInfo();
}

void testingNonProfClass(NonProfEmployee nonProfOne)
{
	nonProfOne.printMainInfo();
	std::cout << "Total Hours Worked: " << nonProfOne.getTotalHoursWorked() << std::endl;
	std::cout << std::endl;

	std::cout << "----------------------------" << std::endl;
	std::cout << "Incrementing work week 4 times" << std::endl;
	std::cout << "----------------------------" << std::endl;
	nonProfOne.incrementWorkWeek();
	nonProfOne.incrementWorkWeek();
	nonProfOne.incrementWorkWeek();
	nonProfOne.incrementWorkWeek();
	std::cout << std::endl;

	nonProfOne.printMainInfo();
	std::cout << "Total Hours Worked: " << nonProfOne.getTotalHoursWorked() << std::endl;
	std::cout << std::endl;

	std::cout << "----------------------------" << std::endl;
	std::cout << "Incrementing absences by 1" << std::endl;
	std::cout << "----------------------------\n" << std::endl;
	nonProfOne.incrementAbsence();

	nonProfOne.printMainInfo();
	std::cout << "Total Hours Worked: " << nonProfOne.getTotalHoursWorked() << std::endl;
	std::cout << std::endl;


}