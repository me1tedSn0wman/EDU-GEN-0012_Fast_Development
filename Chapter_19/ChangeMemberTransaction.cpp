/*
19_33
*/

#include "ChangeMemberTransaction.h"

ChangeMemberTransaction::~ChangeMemberTransaction()
{
}

ChangeMemberTransaction::ChangeMemberTransaction(int empid, int memberId, double dues)
	: ChangeAffiliationTransaction(empid)
	, itsMemberId(memberId)
	, itsDues(dues)
{
}

Affiliation* ChangeMemberTransaction::GetAffiliation() const
{
	return new UnionAffiliation(itsMemberId, itsDues);
}

void ChangeMemberTransaction::RecordMembership(Employee* e)
{
	GpayrollDatabase.AddUnionMember(itsMemberId, e);
}