#ifndef CHANGEMETHODTRANSACTION_H
#define CHANGEMETHODTRANSACTION_H

#include "ChangeEmployeeTransaction.h"

class PaymentMethod;
class ChangeMethodTransaction 
	: public ChangeEmployeeTransaction
{
public:
	virtual ~ChangeMethodTransaction();
	ChangeMethodTransaction(int empid);
	virtual void Change(Employee& e);
};
#endif