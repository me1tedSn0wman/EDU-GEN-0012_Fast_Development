#include "ChangeEmployeeCommissionedTransaction.h"
#include "BiweeklySchedule.h"
#include "CommissionedClassification.h"

ChangeEmployeeCommissionedTransaction::~ChangeEmployeeCommissionedTransaction()
{
}

ChangeEmployeeCommissionedTransaction::ChangeEmployeeCommissionedTransaction(int empid, double commissionRate, double salary)
	: ChangeEmployeeClassificationTransaction(empid)
	, itsSalary(salary)
	, itsCommissionRate(commissionRate)
{
}

PaymentSchedule* ChangeEmployeeCommissionedTransaction::GetSchedule() const
{
	return new BiweeklySchedule();
}

PaymentClassification* ChangeEmployeeCommissionedTransaction::GetClassification() const
{
	return new CommissionedClassification(itsCommissionRate, itsSalary);
}