#ifndef CHANGEEMPLOYEECOMMISSIONEDTRANSACTION_H
#define CHANGEEMPLOYEECOMMISSIONEDTRANSACTION_H

#include "ChangeEmployeeClassificationTransaction.h"

class ChangeEmployeeCommissionedTransaction : public ChangeEmployeeClassificationTransaction {
public :
	virtual ~ChangeEmployeeCommissionedTransaction();
	ChangeEmployeeCommissionedTransaction(int empid, double commissionRate, double salary);
	virtual PaymentSchedule* GetSchedule() const;
	virtual PaymentClassification* GetClassification() const;
private:
	double itsSalary;
	double itsCommissionRate;
};
#endif