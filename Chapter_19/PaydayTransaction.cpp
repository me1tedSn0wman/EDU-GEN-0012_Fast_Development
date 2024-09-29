/*
19_37
19_48
*/


void PaydayTransaction::Execute()
{
	list<int> empids;
	GpayrollDatabase.GetAllEmployeeIds(empids);

	list<int>::iterator i = empids.begin();
	for (; i != empids.end(); i++) {
		int empid = *i;
		if (Employee* e = GpayrollDatabase.GetEmployee(empid)) {
			if (e->IsPayDate(itsPayDate)) {
				Paycheck* pc = new Paycheck(
					e->GetPayPeriodStartDate(itsPayDate), itsPayDate
				);
				itsPaychecks[empid] = pc;
				e->Payday(*pc);
			}
		}
	}
}