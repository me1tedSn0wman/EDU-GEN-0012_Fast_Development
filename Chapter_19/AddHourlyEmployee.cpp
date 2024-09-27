#include "AddHourlyEmployee.h"
#include "WeeklySchedule.h"
#include "HourlyClassification.h"

AddHourlyEmployee::~AddHourlyEmployee();

AddHourlyEmployee::AddHourlyEmployee(int empid, string name, string address, double hourlyRate)
	: AddEmployeeTransaction(empid, name, address)
	, itsHourlyRate(hourlyRate)
{
}

PaymentClassification* AddHourlyEmployee::GetClassification() const
{
	return new HourlyClassification(itsHourlyRate);
}

PaymentSchedule* AddHourlyEmployee::GetSchedule() const
{
	return new WeeklySchedule();
}