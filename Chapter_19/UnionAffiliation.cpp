/*
19_50
*/

namespace
{
	int NumberOfFridaysInPayPeriod(
		const Date& payPeriodStart,
		const Date& payPeriodEnd
	)
	{
		int fridays = 0;
		for (Date day = payPeriodStart; day < payPeriodEnd; day++) {
			if (day.GetDayOfWeek() == Date::friday)
				fridays++;
		}
		return fridays;
	}
}

double UnionAffiliation::CalculateDeductions(Paycheck& pc) const
{
	double totalDues = 0;
	int fridays = NumberOfFridaysInPayPeriod
	(
		pc.GetPayPeriodStartDate(),
		pc.GetPayPeriodEndDate
	);
	totalDues = itsDues * fridays;
	return totalDues;
}