#ifndef CHANGEEMPLOYEESALARIEDTRANSACTION_H
#define CHANGEEMPLOYEESALARIEDTRANSACTION_H

#include "ChangeEmployeeClassificationTransaction.h"

class ChangeEmployeeSalariedTransaction : public ChangeEmployeeSalariedTransaction
{
public :
	virtual ~ChangeEmployeeSalariedTransaction();
	ChangeEmployeeSalariedTransaction(int empid, double salary);
	virtual PaymentSchedule* GetSchedule() const;
	virtual PaymentClassification* GetClassification() const;
private:
	double itsSalary;
};

#endif