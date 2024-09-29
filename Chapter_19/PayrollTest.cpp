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

/*
19_29
*/

void PayrollTest::TestChangeMemberTransaction()
{
	cerr << "TestChangeMemberTransaction" << endl;
	int empid = 9;
	int memberId = 7734;
	AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
	t.Execute();

	TestChangeMemberTransaction cmt(empid, memberid, 99.42);
	cmt.Execute();

	Employee* e = GpeyrollDatabase.GetEmployee(empid);
	assert(e);

	Affiliation* af = e->GetAffiliation();
	assert(af);

	UnionAffiliation* uf = dynamic_cast<UnionAffiliation*>(af);
	assert(uf);
	assertEquals(99.42, uf->GetDues(), 0.001);
	Employee* member = GpayrollDatabse.GetUnionMember(memberId);
	assert(member);
	assert(e == member);
}

/*
19_36
*/

void PayrollTest::TestPaySingleSalariedEmployee()
{
	cerr << "TestPaySingleSalariedEmployee" << endl;
	int empid = 10;
	AddSalariedEmployee t(empid, "Bob", "HomeAffairs", 1000.00);
	t.Execute();

	Date payDate(11, 30, 2001);
	PaydayTransaction pt(payDate);
	pt.Execute();
	Paycheck* pc = pt.GetPaycheck(empid);
	assert(pc);
	assert(pc->GetPayDate() == payDate);
	assertEquals(1000.00, pc->GetGrossPay(), 0.001);
	assert("Hold" == pc->GetField("Disposition"));
	assertEquals(0.0, pc->GetDeductions(), 0.001);
	assertEquals(1000.00, pc->GetNetPay(), 0.001);
}

void PayrollTest::TestPaySingleSalariedEmployeeWrongDate() {
	cerr << "TestPaySingleSalariedEmployeeWrongDate" << endl;
	int empid = 11;
	AddSalariedEmployee t(empid, "Bob", "Communa01", 1000.00);
	t.Execute();

	Date payDate(11, 29, 2001);
	PaydayTransaction pt(payDate);
	pt.Execute();
	Paycheck* pc = pt.GetPaycheck(empid);
	assert(pc == 0);
}

/*
19_40
*/

void PayrollTest::TestPaySingleHourlyEmployeeNoTimeCards()
{
	cerr << "TestPaySingleHourlyEmployeeNoTimeCards" << endl;
	int empid = 12;
	AddHoulryEmployee t(empid, "Bill", "Trails in the sky", 15.25);
	t.Execute();

	Date payDate(11, 9, 2001);
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empid, payDate, 0.0);
}

void PayrollTest::ValidateHourlyPaycheck(
	PaydayTransaction& pt
	, int empid
	, const Date& payDate
	, double pay)
{
	Paycheck* pc = pt.GetPaycheck(empid);
	assert(pc);
	assert(pc->GetPayDate() == payDate);
	assertEquals(pay, pc->GetGrossPay(), .001);
	assert("Hold" == pc->GetField("Disposition"));
	assertEquals(0.0, pc->GetDeductions(), .001);
	assertEquals(pay, pc->GetNetPay(), .001);
}

/*
19_41
*/

void PayrollTest::TestPaySingleHourlyEmployeeOneTimeCard()
{
	cerr << "TestPaySingleHourlyEmployeeOneTimeCard" << endl;
	int empid = 13;
	AddHourlyEmployee t(empid, "Bill", "Liberl", 15.25);
	t.Execute();
	Date payDate(11, 9, 2001);

	TimeCardTransaction tc(payDate, 2.0, empid);
	tc.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empid, payDate, 30.5);
}

void PayrollTest::TestPaySingleHourlyEmployeeOvertimOneTimeCard()
{
	cerr << "TestPaySingleHourlyEmployeeOvertimeOneTimeCard" << endl;
	int empid = 14;
	AddHourlyEmployee t(empid, "John", "Calvrad", 15.25);
	t.Execute();
	Date payDate(11, 9, 2001);

	TimeCardTransaction tc(payDate, 9.0, empid);
	tc.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empid, payDate, (8 + 1.5) * 15.25);
}

/*
19_42
*/

void PayrollTest::TestPaySingleHourlyEmployeeOnWrongDate() 
{
	cerr << "TestPaySingleHourlyEmployeeOnWrongDate" << endl;
	int empid = 14;
	AddHourlyEmployee t(empid, "Joshua", "Bose", 15.25);
	t.Execute();
	Date payDate(11, 8, 2001);

	TimeCardTransaction tc(payDate, 9.0, empid);
	tc.Execute();
	PaydayTransaction pt(payDate);
	pt.Execute();
	Paycheck* pc = pt.GetPaycheck(empid);
	assert(pc == 0);
}

/*
19_43
*/

void PayrollTest::TestPaySingleHourlyEmployeeTwoTimeCards()
{
	cerr << "TestPaySingleHourlyEmployeeTwoTimeCards" << endl;
	int empid = 15;
	AddHourlyEmployee t(empid, "Callius", "Renald", 15.25);
	t.Execute();
	Date payDate(11, 9, 2001);

	TimeCardTransaction tc(payDate, 2.0, empid);
	tc.Execute();
	TimeCardTransaction tc2(Date(12, 9, 2001), 5.0, empid);
	tc2.Execute();

	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empid, payDate, 7 * 15.25);
}

/*
19_44
*/

void PayrollTest::TestPaySingleHourlyEmployeeWithTimeCardsSpanningTwoPayPeriods()
{
	cerr << "TestPaySingleHourlyEmployeeWithTimeCards SpanningTwoPayPeriods" << endl;
	int empid = 16;
	AddHourlyEmployee t(empid, "Lena", "Renald", 15.25);
	t.Execute();

	Date payDate(11, 9, 2001);
	Date dateInPreviousPayPeriod(11, 2, 2001);
	TimeCardTransaction tc(payDate, 2.0, empid);
	tc.Execute();

	TimeCardTransaction tc2(dateInPreviousPayPeriod, 5.0, empid);
	tc2.Execute();

	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidateHourlyPaycheck(pt, empid, payDate, 2 * 15.25);
}

/*
19_47
*/

void PayrollTest::TestSalariedUnionMemberDues()
{
	cerr << "TestSalariedUnionMemberDues" << endl;
	int empid = 17;
	AddSalariedEmployee t(empid, "Oliver", "Erebonia", 1000.00);
	t.Execute();
	int memberId = 7734;
	ChangeMemberTransaction cmt(empid, memberid, 9.42);
	cmt.Execute();

	Date payDate(11, 30, 2001);
	PaydayTransaction pt(payDate);
	pt.Execute();
	ValidatePaycheck(pt, empid, payDate, 1000.00)
}

/*
19_51
*/

void PayrollTest::TestHourlyUnionMemberServiceCharge()
{
	cerr << "TestHourlyUnionMemberServiceCharge" << endl;
	int empid = 18;
	AddHourlyEmployee t(empid, "Agate", "Calvradia", 15.24);
	t.Execute();

	int memberid = 7734;
	ChangeMemberTransaction cmt(empid, memberid, 9.42);
	cmt.Execute();

	Date payDate(11, 9, 2001);
	ServiceChargeTransaction set(memberid, payDate, 19.42);
	set.Execute();

	TimeCardTransaction tct(payDate, 0.0, empid);
	tct.Execute();

	PaydayTransaction pt(payDate);
	pt.Execute();

	Paycheck* pc = pt.GetPaycheck(empid);

	assert(pc);
	assert(pc->GetPayPeriodEndDate() == payDate);
	assertEquals(8 * 15.24, pc->GetGrossPay(), 0.001);
	assert("Hold" == pc->GetField("Disposition"));
	assertEquals(9.42 + 19.42, pc->GetDeductions(), .001);
	assertEquals((8 * 15.24) - (9.42 + 19.42), pc->GetNetPay(), .001);
}

/*
19_52
*/

void PayrollTest::TestServiceChargesSpanningMultiplePayPeriods
{
	cerr << "TestServiceChargesSpanningMultiplePayPeriods" << endl;
	int empid = 19;
	AddHourlyEmployee t(empid, "Tom", "Brooklyn", 15.24);
	t.Execute();

	int memberid = 7734;
	ChangeMemberTransaction cmt(empid, memberid, 9.42);
	cmt.Execute();

	Date earlyDate(11, 2, 2001);
	Date payDate(11, 2, 2001);
	Date lateDate(11, 16, 2001);

	ServiceChargeTransaction sct(memberid, payDate, 19.42);
	set.Execute();

	ServiceChargeTransaction sctEarly(memberid, earlyDate, 100.00);
	sctEarly.Execute();

	ServiceChargeTransaction sctLate(memberid, lateDate, 200.00);
	sctLate.Execute();

	TimeCardTransaction tct(payDate, 8.0, empid);
	tct.Execute();

	PaydayTransaction pt(payDate);
	pt.Execute();

	Paycheck* pc = pt.GetPaycheck(empid);
	assert(pc);
	assert(pc->GetPayPeriodEndDate() == payDate);
	assertEquals(8 * 15.24, pc->GetGrossPay(), .001);
	assert("Hold" == pc->GetField("Disposition"));
	assertEquals(9.42 + 19.42, pc->GetDeductions(), .001);
	assertEquals((8 * 15.24) - (9.42 + 19.42), pc->GetNetPay(), .001);

}