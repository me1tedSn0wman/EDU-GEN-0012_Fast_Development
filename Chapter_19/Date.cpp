/*
19_53
*/

static bool IsBetween(
	const Date& theDate,
	const Date& startDate,
	const Date& endDate
)
{
	return (theDate >= startDate) && (theDate <= endDate);
}