#pragma once

#include "Employee.h"



class ProfEmployee : public Employee
{
public:

	ProfEmployee(std::string name, size_t monthlySalary);

	size_t monthlySalary() const;


	// -------------------------
	// Assignement Methods below
	// -------------------------

	double weeklySalary() const;

	size_t healthContribution() const;

	size_t vacationDays() const;

private:
	size_t m_monthlySalary;
	size_t m_vacationDays;
};