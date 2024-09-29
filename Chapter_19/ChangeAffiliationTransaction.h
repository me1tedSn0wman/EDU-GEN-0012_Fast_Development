/*
19_30
*/

#ifndef CHANGEAFFILIATIONTRANSACTION_H
#define CHANGEAFFILIATIONTRANSACTION_H

#include "ChangeEmployeeTransaction.h"

class Affiliation;
class UnionAffiliation;
class ChangeAffiliationTransaction
	: public ChangeEmployeeTransaction
{
public:
	virtual ~ChangeAffiliationTransaction();
	ChangeAffiliationTransaction(int empid);
	virtual Affiliation* GetAffiliation() const = 0;
	virtual void RecordMembership(Employee* e) = 0;
	virtual void Change(Emplyee& e);
};

#endif;