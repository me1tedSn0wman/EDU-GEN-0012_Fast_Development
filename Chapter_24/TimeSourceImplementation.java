import java.util.*;

public class TimeSourceImplementation
{
	private Vector itsObservers = new Vector();
	
	public void notife(int hours, int minutes, int seconds)
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
		itsOBservers.add(observer);
	}
	
}