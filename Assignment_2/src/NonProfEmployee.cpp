#pragma once

#include "NonProfEmployee.h"

NonProfEmployee::NonProfEmployee(std::string name, size_t hourlyRate)
	: Employee(name), m_hourlyRate(hourlyRate), hoursWorked(40), totalHoursWorked(0)
{
}

double NonProfEmployee::getHourlyRate() const
{
	return m_hourlyRate;
}

void NonProfEmployee::incrementWorkWeek()
{
	totalHoursWorked += hoursWorked;
}

size_t NonProfEmployee::getTotalHoursWorked() const
{
	return totalHoursWorked;
}

double NonProfEmployee::weeklySalary() const
{
	return m_hourlyRate * hoursWorked;
}

size_t NonProfEmployee::healthContribution() const
{
	size_t reduction = getUnexcusedAbsences() * 100;

	if (reduction > 2000)
		return 0;

	return 2000 - (getUnexcusedAbsences() * 100);
}

size_t NonProfEmployee::vacationDays() const
{
	// 1 Vacation day per 137 hours worked

	return totalHoursWorked / 137;
}