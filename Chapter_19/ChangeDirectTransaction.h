#ifndef CHANGEDIRECTTRANSACTION_H
#define CHANGEDIRECTTRANSACTION_H

#include "ChangeMethodTransaction.h"

class ChangeDirectTransaction : public ChangeMethodTransaction
{
public:
	virtual ~ChangeDirectTransaction();
	ChangeDirectTransaction(int empid, string bank, string account);
	virtual PaymentMethod* GetMethod() const;
private:
	string itsBank;
	string itsAccount;
};

#endif