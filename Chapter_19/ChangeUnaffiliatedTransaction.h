/*
19_34
*/

#ifndef CHANGEUNAFFILIATEDTRANSACTION_H
#define CHANGEUNAFFILIATEDTRANSACTION_H

#include "ChangeAffiliationTransaction.h"

class ChangeUnaffiliatedTransaction :
	public ChangeAffiliationTransaction
{
public:
	virtual ~ChangeUnaffiliatedTransaction();
	ChangeUnaffiliatedTransaction(int empid);

	virtual Affiliation* GetAffiliation() const;
	virtual void RecordMembership(Employee* e);
};

#endif