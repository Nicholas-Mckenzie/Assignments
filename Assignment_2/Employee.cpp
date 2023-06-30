

#include "Employee.h"




Employee::Employee(std::string name)
	: m_name(name), unexcusedAbsences(0)
{
}

void Employee::printMainInfo() const
{
	std::cout << "Employee: ";
	printName();
	std::cout << "Unexcused Absences: " << getUnexcusedAbsences() << std::endl;
	std::cout << "Weekly Salary: " << weeklySalary() << std::endl;
	std::cout << "HealthContributions: " << healthContribution() << std::endl;
	std::cout << "Vacation Days: " << vacationDays() << std::endl;
}

void Employee::printName() const
{
	std::cout << m_name << std::endl;
}

void Employee::printAbscences() const
{
	std::cout << m_name << " has " << unexcusedAbsences << std::endl;
}

void Employee::incrementAbsence()
{
	unexcusedAbsences++;
}

size_t Employee::getUnexcusedAbsences() const
{
	return unexcusedAbsences;
}




