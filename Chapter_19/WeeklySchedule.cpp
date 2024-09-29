bool WeeklySchedule::IsPayDate(const Date& theDate) const
{
	return theDate.GetDayOfWeek() == Date::friday;
}