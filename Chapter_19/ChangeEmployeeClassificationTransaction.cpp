/*
19_26
*/

#include "ChangeEmployeeClassificationTransaction.h"

ChangeEmployeeClassificationTransaction::~ChangeEmployeeClassificationTransaction()
{
}

ChangeEmployeeClassificationTransaction::ChangeEmployeeClassificationTransaction(int empid)
	: ChangeEmployeeTransaction(empid)
{
}

void ChangeEmployeeClassificationTransaction::Change(Employee& e)
{
	e.SetClassification(GetClassification());
	e.SetSchedule(GetSchedule());
}