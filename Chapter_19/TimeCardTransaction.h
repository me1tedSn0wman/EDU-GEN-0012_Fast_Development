/*
19_14
*/

#ifndef TIMECARDTRANSACTION_H
#define TIMECARDTRANSACTION_H

#include "Transaction.h"

class TimeCardTransaction : public Transaction
{
public:
	virtual ~TimeCardTransaction();
	TimeCardTransaction(long date, double hours, int empid);
	virtual void Execute();
private:
	int itsEmpid;
	long itsDate;
	double itsHours;
};

#endif