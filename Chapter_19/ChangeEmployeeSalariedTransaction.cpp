#include "ChangeEmployeeSalariedTransaction.h"
#include "MonthlySchedule.h"
#include "SalariedClassification.h"

ChangeEmployeeSalariedTransaction::~ChangeEmployeeSalariedTransaction()
{
}

ChangeEmployeeSalariedTransaction::ChangeEmployeeSalariedTransaction(int empid, double salary)
	:ChangeEmployeeClassificationTransaction(empid)
	, itsSalary(salary)
{
}

PaymentSchedule* ChangeEmployeeSalariedTransaction::GetSchedule() const
{
	return new MonthlySchedule();
}

PaymentClassification* ChangeEmployeeSalariedTransaction::GetClassification() const
{
	return new SalariedClassification(itsSalary);
}