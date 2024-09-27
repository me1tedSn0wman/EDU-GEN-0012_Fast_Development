/*
19_25
*/

#ifndef CHANGEEMPLOYEECLASSIFICATIONTRANSACTION_H
#define CHANGEEMPLOYEECLASSIFICATIONTRANSACTION_H

#include "ChangeEmployeeTransaction.h"

class PaymentClassification;
class PaymentSchedule;
class ChangeEmployeeClassificationTransaction : 
	public ChangeEmployeeTransaction
{
public:
	virtual ~ChangeEmployeeClassificationTransaction();
	ChangeEmployeeClassificationTransaction(int empid);
	virtual void Change(Employee& e);
	virtual PaymentClassification* GetClassification() const = 0;
	virtual PaymentSchedule* GetSchedule() const = 0;
};

#endif