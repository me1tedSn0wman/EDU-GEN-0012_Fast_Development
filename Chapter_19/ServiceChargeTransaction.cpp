/*
19_18
*/

#include "ServiceChargeTransaction.h"
#include "Employee.h"
#include "PayrollDatabase.h"
#include "ServiceCharge.h"
#include "UnionAffiliation.h"

extern PayrollDatabase GpayrollDatabase;

ServiceChargeTransaction::~ServiceChargeTransaction() 
{
}

ServiceChargeTransaction::ServiceChargeTransaction(long date, double amount, int memberID)
	: itsDate(date)
	, itsAmount(amount)
	, itsMemberID(memberID)
{
}

void ServiceChargeTransaction::Execute() 
{
	Employee* e = GpayrollDatabase.GetUnionMember(itsMemberID);
	Affiliation* af = e->GetAffiliation();
	if (UnionAffiliation* uaf = dynamic_cast<UnionAffiliation*>(af)) {
		uaf->AddServiceCharge(itsDate, itsCharge);
	}
}