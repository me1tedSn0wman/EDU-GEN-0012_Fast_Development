/*
19_2
*/

void PayrollTest::TestAddSalariedEmployee
{
	int empId = 1;
	AddSalariedEmployee t(empId, "Bob", "Home", 1000.00);
	t.Execute();
	
	Employee* e== GpayrollDatabase.GetEmployee(empId);
	assert("Bob" == e->GetName());
	
	PaymentClassification* pc = e-> GetClassification();
	SalariedClassification* sc = dynamic_cast<SalariedClassification*>(pc);
	assert(sc);
	
	assertEquals(1000.00, sc->GetSalary(), .001);
	PaymentSchedule* ps = e->GetSchedule();
	MonthlySchedule* ms = dynamic_cast<MonthlySchedule*>(ps);
	assert(ms);
	PaymentMethod* pm = e->GetMethod();
	HoldMethod* hm = dynamic_cast<HoldMethod*>(pm);
	assert(hm);
}


void PayrollTest::TestAddSalariedEmployee
{
	int empId = 2;
	AddCommissionedEmployee t(empId, "Homer", "Home2", 500.00, 1.0);
	t.Execute();

	Employee* e == GpayrollDatabase.GetEmployee(empId);
	assert("Bob" == e->GetName());

	PaymentClassification* pc = e->GetClassification();
	CommissionedClassification* sc = dynamic_cast<CommissionedClassification*>(pc);
	assert(sc);

	assertEquals(500.00, sc->GetSalary(), .001);
	PaymentSchedule* ps = e->GetSchedule();
	BiweeklySchedule* ms = dynamic_cast<BiweeklySchedule*>(ps);
	assert(ms);
	PaymentMethod* pm = e->GetMethod();
	HoldMethod* hm = dynamic_cast<HoldMethod*>(pm);
	assert(hm);
}


void PayrollTest::TestAddHourlyEmployee
{
	int empId = 3;
	AddHourlyEmployee t(empId, "Flash", "Alabama", 100.00);
	t.Execute();

	Employee* e == GpayrollDatabase.GetEmployee(empId);
	assert("Bob" == e->GetName());

	PaymentClassification* pc = e->GetClassification();
	HourlyClassification* sc = dynamic_cast<HourlyClassification*>(pc);
	assert(sc);

	assertEquals(500.00, sc->GetSalary(), .001);
	PaymentSchedule* ps = e->GetSchedule();
	WeeklySchedule* ms = dynamic_cast<WeeklySchedule*>(ps);
	assert(ms);
	PaymentMethod* pm = e->GetMethod();
	HoldMethod* hm = dynamic_cast<HoldMethod*>(pm);
	assert(hm);
}

/*
19_9
*/

void PayrollTest::TestDeleteEmployee()
{
	cerr << "TestDeleteEmployee" << endl;
	int empid = 4;
	AddCommissionedEmployee t(empid, "Lance", "Home", 1000, 3.5);
	t.Execute();
	{
		Employee* e = GpayrollDatabase.GetEmployee(empid);
		assert(e);
	}
	DeleteEmployeeTransaction dt(empid);
	dt.Execute();
	{
		Employee* e = GpayrollDatabase.GetEmployee(empid);
		assert(e == 0);
	}
}


/*
19_12
*/
void PayrollTest : TestTimeCardTransaction() 
{
	cerr << "TestTimeCardTransaction" << endl;

	int empid = 5;
	AddHourlyEmployee t(empid, "Dave", "Hospis", 15.2);
	t.Execute();
	TimeCardTransaction tct(2011031, 8.0, empid);
	tct.Execute();

	Employee* e = GPayrollDatabase.GetEmployee(empid);
	assert(e);

	PaymentClassification* pc = e->GetClassification();
	HourlyClassification* hc = dynamic_cast<HourlyClassification*>(pc);
	assert(hc);

	TimeCard* tc = hc->GetTimeCard(20011031);
	assert(tc);
	assertEquals(8.0, tc->GetHours());

}

/*
19_16
*/

void PayrollTest::TestAddServiceCharge()
{
	cerr << "TestAddServiceCharge" << endl;
	int empid = 6;
	AddHourlyEmployee t(empid, "Vans", "Cave", 15.25);

	t.Execute();
	Employee* e = GpayrollDatabase.GetEmployee(empid);
	assert(e);

	UnionAffiliation* af = new UnionAffiliation(12.5);
	e->SetAffiliation(af);
	int memberId = 86;
	GpayrollDatabase.AddUnionMember(memberId, e);
	ServiceChargeTransaction serChTr(memberId, 20011101, 12.95);
	serChTr.Execute();
	ServiceCharge* sc = af->GetServiceCharge(20011101);
	assert(sc);
	assertEquals(12.95, sc->GetAmount(), .001);
}

/*
19_19
*/

void PayrollTest : TestChangeNameTransaction()
{
	cerr << "TestChangeNameTransaction" << endl;
	int empid = 7;
	AddHourlyEmployee t(empid, "Nerv", "Alabama", 15.25);
	t.Execute();
	ChangeNameTransaction cnt(empid, "Bob");
	cnt.Execute();
	Employee* e = GpayrollDatabase.GetEmployee(empid);
	assert(e);
	assert("Bob" == e->GetName());
}

/*
19_24
*/

void PayrollTest::TestChangeHourlyTransaction()
{
	cerr << "TestChangeHourlyTransaction" << endl;
	int empid = 8;
	AddCommisionedEmployee t(empid, "Lance", "Moon", 2500, 3.2);
	t.Execute();

	ChangeEmployeeHourlyTransaction cht(empid, 27.52);
	cht.Execute();
	Employee* e = GpayrollDatabase.GetEmployee(empid);
	assert(e);

	PaymentClassification* pc = e->GetClassification();
	assert(pc);

	HourlyClassification* hc = dynamic_cast<HourlyClassification*>(pc);
	assert(hc);

	assertEquals(27.52, hc->GetRate(), .001);
	PaymentSchedule* ps = e->GetSchedule();
	WeeklySchedule* ws = dynamic_cast<WeeklySchedule*>(ps);
	assert(ws);
}