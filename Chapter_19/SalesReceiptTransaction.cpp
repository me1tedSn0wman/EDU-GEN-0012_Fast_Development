#include "SalesReceiptTransaction.h"
#include "SalesReceipt.h"
#include "Employee.h"
#include "PayrollDatabase.h"
#include "CommisionedClassification.h"

extern PayrollDatabase GpayrollDatabase;

SalesReceiptTransaction:: ~SalesReceiptTransaction() 
{
}

SalesReceiptTransaction::SalesReceiptTransaction(long date, double amount, int empid)
	: itsDate(date)
	, itsAmount(amount)
	, itsEmpID(empid)
{
	Employee* e = GpayrollDatabase.GetEmployee(empid);
	if (e) {
		PaymentClassification* pc = e->GetClassification();
		if (CommisionedClassification* cc = dynamic_cast<CommisionedClassification*>(pc)) {
			cc->AddSalesReceipt(new SalesReceipt(itsDate, itsAmount))
		}
		else {
			throw("Tried to add sales receipt to non comissioned employee")
		}
	}
	else {
		throw("No such Employee");
	}
}