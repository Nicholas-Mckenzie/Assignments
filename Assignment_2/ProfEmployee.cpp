
#include "ProfEmployee.h"


ProfEmployee::ProfEmployee(std::string name, size_t monthlySalary)
	: Employee(name), m_monthlySalary(monthlySalary), m_vacationDays(14)
{
}

size_t ProfEmployee::monthlySalary() const
{
	return m_monthlySalary;
}


// -----------------------------------------
// Assignement Methods implementations below
// -----------------------------------------
double ProfEmployee::weeklySalary() const
{
	return (double)m_monthlySalary / 4;
}

size_t ProfEmployee::healthContribution() const
{
	size_t reduction = getUnexcusedAbsences() * 100;

	if (reduction > 2000)
		return 0;

	return 2000 - (getUnexcusedAbsences() * 100);
}

size_t ProfEmployee::vacationDays() const
{
	if (getUnexcusedAbsences() > m_vacationDays)
		return 0;

	return m_vacationDays - getUnexcusedAbsences();
}