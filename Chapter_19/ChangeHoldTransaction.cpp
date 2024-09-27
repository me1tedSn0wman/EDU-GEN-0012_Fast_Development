#include "ChangeHoldTransaction.h"

ChangeHoldTransaction::~ChangeHoldTransaction()
{
}

ChangeHoldTransaction::ChangeHoldTransaction(int empid, string address)
	: ChangeMethodTransaction(empid)
	, itsAddress(address)
{
}

PaymentMethod* ChangeHoldTransaction::GetMethod() const
{
	return new HoldMethod(itsAddress);
}