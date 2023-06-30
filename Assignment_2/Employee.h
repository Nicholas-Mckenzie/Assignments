#pragma once

#include <string>
#include <iostream>


class Employee
{
public:

	Employee(std::string name);


	virtual double weeklySalary() const = 0;

	// Returns total health contribution company will provide for a claim
	virtual size_t healthContribution() const = 0;

	virtual size_t vacationDays() const = 0;

	// Prints all of the assignment info so weekly salary, health contribution, and vacation days
	void printMainInfo() const;

	// Prints employee name to console
	void printName() const;
	
	// Prints total unexcused abscences employee has to console
	void printAbscences() const;

	// Increments total unexcused abscences employee has by 1
	void incrementAbsence();

	// Returns total unexcused abscences employee has
	size_t getUnexcusedAbsences() const;

private:
	std::string m_name;
	size_t unexcusedAbsences;
};