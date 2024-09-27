/*
19_17
*/

#ifndef SERVICECHARGETRANSACTION_H
#define SERVICECHARGETRANSACTION_H

#include "Transaction.h"

class ServiceChargeTransaction : public Transaction
{
public:
	virtual ~ServiceChargeTransaction();
	ServiceChargeTransaction(long date, double amount, int memberID);
	virtual void Execute();
private:
	long itsDate;
	double itsAmount;
	int itsMemberID;
};

#endif