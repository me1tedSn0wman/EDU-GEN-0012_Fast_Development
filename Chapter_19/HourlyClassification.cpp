/*
19_45
*/

double HourlyClassification::CalculatePay(Paycheck& pc) const
{
	double totalPay = 0;
	Date payPeriod = pc.GetPayDate();
	map<Date, TimeCard*>::const_iterator i;
	for (i = itsTimeCards.begin(); i != itsTimeCards.end(); i++) {
		TimeCard* tc = (*i).second;
		if (IsInPayPeriod(tc, playPeriod))
			totalPay += CalculatePayForTimeCard(tc);
	}
	return totalPay;
}

bool HourlyClassification::IsInPayPeriod(TimeCard* tc, const Date& payPeriod) const
{
	Date payPeriodEndDate = payPeriod;
	Date payPeriodStartDate = payPeriod - 5;
	Date timeCardDate = tc->GetDate();
	return (timeCardDate >= payPeriodStartDate) && (timeCardDate <= payPeriodEndDate);
}

double HourlyClassification::CalculatePayForTimeCard(TimeCard* tc) const
{
	double hours = tc->GetHours();
	double overtime = max(0.0, hours - 8.0);
	double straightTime = hours - overtime;
	return straightTime * itsRate + overtime * itsRate * 1.5;
}