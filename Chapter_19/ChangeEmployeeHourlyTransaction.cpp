/*
19_28
*/

#include "ChangeEmployeeHourlyTransaction.h"
#include "WeeklySchedule.h"
#include "HourlyClassification.h"

ChangeEmployeeHourlyTransaction::~ChangeEmployeeHourlyTransaction() 
{
}

ChangeEmployeeHourlyTransaction::ChangeEmployeeHourlyTransaction(int empid, double hourlyRate)
	: ChangeEmployeeClassificationTransaction(empid)
	, itsHourlyRate(hourlyRate)
{
}

PaymentSchedule* ChangeEmployeeHourlyTransaction::GetSchedule() const
{
	return new WeeklySchedule();
}

PaymentClassification* ChangeEmployeeHourlyTransaction::GetClassification() const
{
	return new HourlyClassification(itsHourlyRate);
}
