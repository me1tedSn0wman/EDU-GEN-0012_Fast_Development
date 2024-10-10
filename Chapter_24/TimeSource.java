import java.util.*;

/*
public class TimeSource
{
	private Vector itsObservers = new Vector();
	
	protected void notify(int hours, int minutes, int seconds)
	{
		Iterator i = itsObservers.iterator();
		while(i.hasNext())
		{
			ClockObserver observer = (ClockObserver) i.next();
			observer.update(hours, minutes, seconds);
		}
	}
	
	public void registerObserver(ClockObserver observer)
	{
		itsObservers.add(observer);
	}
}
*/


/*
public interface TimeSource
{
	public void registerObserver(ClockObserver observer);
}
*/

public interface TimeSource
{
	public int getHours();
	public int getMinutes();
	public int getSeconds();
}
