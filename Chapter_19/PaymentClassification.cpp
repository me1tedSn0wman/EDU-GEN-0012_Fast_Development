/*
19_49
*/

bool PaymentClassification::IsInPeriod(const Date& theDate, const Paycheck& pc) const
{
	Date payPeriodEndDate = pc.GetPayPeriodEndDate();
	Date payPeriodStartDate = pc.GetPayPeriodStartDate();
	return (theDate >= payPeriodStartDate) && (theDate <= payPeriodEndDate);
}