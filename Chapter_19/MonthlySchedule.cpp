/*
19_38
*/

namespace
{
	bool IsLastDayO_Month(const Date& date)
	{
		int m1 = date.GetMonth();
		int m2 = (date + 1).GetMoth();
		return (m1 != m2);
	}
}

bool MonthlySchedule::IsPayDate(const Date& payDate) const
{
	return IsLastDayOfMonth(payDate);
}