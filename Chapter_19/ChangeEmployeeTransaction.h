/*
19_20
*/

#ifndef CHANGEEMPLOYEETRANSACTION_H
#define CHANGEEMPLOYEETRANSACTION_H

#include "Transaction.h"
#include "Employee.h"

class ChangeEmployeeTransaction : public Transaction
{
public:
	ChangeEmployeeTransaction(int empid);
	virtual ~ChangeEmployeeTransaction();
	virtual void Execute();
	virtual void Change(Employee& e) = 0;
private:
	int itsEmpID;
};

#endif