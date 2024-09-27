/*
19_27
*/

#ifndef CHANGEEMPLOYEEHOURLYTRANSACTION_H
#define CHANGEEMPLOYEEHOURLYTRANSACTION_H

#include "ChangeEmployeeClassificationTransaction.h"

class ChangeEmployeeHourlyTransaction : public ChangeEmployeeClassificationTransaction
{
public :
	virtual ~ChangeEmployeeHourlyTransaction();
	ChangeEmployeeHourlyTransaction(int empid, double hourlyRate);
	virtual PaymentSchedule* GetSchedule() const;
	virtual PaymentClassification* GetClassification() const;
private:
	double itsHourlyRate;
};

#endif