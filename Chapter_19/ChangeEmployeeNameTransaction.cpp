/*
19_23
*/

#include "ChangeEmployeeNameTransaction.h"

ChangeEmployeeNameTransaction::~ChangeEmployeeNameTransaction()
{
}

ChangeEmployeeNameTransaction::ChangeEmployeeNameTransaction(int empid, string name)
	:ChangeEmployeeTransaction(empid)
	, itsName(name)
{
}

void ChangeEmployeeNameTransaction::Change(Employee& e) {
	e.SetName(itsName);
}