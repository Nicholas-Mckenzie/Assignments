#pragma once


#include "Employee.h"

class NonProfEmployee : public Employee
{
public:

	NonProfEmployee(std::string name, size_t hourlyRate);

	double getHourlyRate() const;

	// Adds hoursWorked to total hours worked
	void incrementWorkWeek();

	size_t getTotalHoursWorked() const;

	// -------------------------
	// Assignement Methods below
	// -------------------------

	double weeklySalary() const;

	size_t healthContribution() const;

	size_t vacationDays() const;

	

private:
	double m_hourlyRate;
	size_t hoursWorked;
	size_t totalHoursWorked;
};
