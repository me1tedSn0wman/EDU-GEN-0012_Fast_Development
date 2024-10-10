//public class MockTimeSink implements TimeSink
public class MockTimeSink implements Observer
{
	private int itsHours;
	private int itsMinutes;
	private int itsSeconds;
	private TimeSource itsSource;
	
	public MockTimeSink(TimeSource source)
	{
		itsSource = source;
	}
	
	public int getSeconds()
	{
		return itsSeconds;
	}
	
	public int getMinutes()
	{
		return itsMinutes;
	}
	
	public int getHours()
	{
		return itsHours;		
	}
	
	public void update()
	{
		itsHours = itsSource.getHours();
		itsMinutes = itsSource.getMinutes();
		itsSeconds = itsSource.getSeconds();
	}
	
	/*
	public void setTime(int hours, int minutes, int seconds)
	{
		itsHours = hours;
		itsMinutes = minutes;
		itsSeconds = seconds;
	}
	*/
}