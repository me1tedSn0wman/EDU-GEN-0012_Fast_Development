#ifndef CHANGEHOLDTRANSACTION_H
#define CHANGEHOLDTRANSACTION_H

#include "ChangeMethodTransaction.h"

class ChangeHoldTransaction : public ChangeMethodTransaction
{
public:
	virtual ~ChangeHoldTransaction();
	ChangeHoldTransaction(int empid, string address);
	virtual PaymentMethod* GetMethod() const;
private:
	string itsAddress;
};

#endif