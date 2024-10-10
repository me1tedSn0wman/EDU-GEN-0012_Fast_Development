public class ClockDriver implements ClockObserver
{
	private TimeSink itsSink;
	
	public ClockDriver(TimeSource source, TimeSink sink)
	{
		source.setDriver(this);
		itsSink = sink;
	}
	
	public void update(int hours, int nimutes, int seconds)
	{
		itsSink.setTime(hours, minutes, seconds);
	}
}