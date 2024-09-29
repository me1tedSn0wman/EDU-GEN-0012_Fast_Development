/*
19_35
*/

#include "changeUnaffiliatedTransaction.h"
#include "NoAffiliation.h"
#include "UnionAffiliation.h"
#include "PayrollDatabase.h"

extern PayrollDatabase GpayrollDatabase;

ChangeUnaffiliatedTransaction::~ChangeUnaffiliatedTransaction()
{
}

ChangeUnaffiliatedTransaction::ChangeUnaffiliatedTransaction(int empid)
	: ChangeAffiliationTransaction(empid)
{
}

Affiliation* ChangeUnaffiliatedTransaction::GetAffiliation() const
{
	return new NoAffiliation();
}

void ChangeUnaffiliatedTransaction::RecordMembership(Emplyee* e)
{
	Affiliation* af = e->GetAffiliation();
	if (UnionAffiliation* uf = dynamic_cast<UnionAffiliation*>(af))
	{
		int memberId = uf->GetMemeberId();
		GpayrollDatabase.RemoveUnionMember(memberId);
	}
}