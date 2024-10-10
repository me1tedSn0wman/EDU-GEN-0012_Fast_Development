import java.util.*;


/*
public class MockTimeSource implements TimeSource
{
	private Vector itsObservers = new Vector();
	
//	private ClockObserver itsObserver;
	
	public void setTime(int hours, int minutes, int seconds)
	{
		Iterator i = itsObservers.iterator();
		while(i.hasNext)
		{
			ClockObserver observer = (ClockObserver) i.next();
			observer.update(hours, minutes, seconds);
			
		}
		
		//itsObserver.update(hours, minutes, seconds);
		
	}
	
	public void registerObserver(ClockObserver observer)
	{
		itsObservers.add(observer);
		
	}
	
	
	public void setDriver(ClockObserver observer)
	{
		itsObserver = observer;
	}
	
	
}
*/

/*
public class MockTimeSource extends TimeSource
{
	public void setTime(int hours, int minutes, int seconds)
	{
		notify(hours, minutes, seconds);
	}
}
*/

/*
public class MockTimeSource implements TimeSource
{
	TimeSourceImplementation tsImp = new TimeSourceImplementation();
	
	public void registerObserver(ClockObserver observer)
	{
		tsImp.registerObserver(observer);
	}
	
	public void setTime(int hours, int minutes, int seconds)
	{
		tsImp.notify(hours, minutes, seconds);
	}
	
}
*/

public class MockTimeSource extends Subject implements TimeSource
{
	private int itsHours;
	private int itsMinutes;
	private int itsSeconds;
	
	
	public void setTime(int hours, int minutes, int seconds)
	{
		itsHours = hours;
		itsMinutes = minutes;
		itsSeconds = seconds;
		notifyObservers();
		
	}
	
	public int getHours()
	{
		return itsHours;
	}
	
	public int getMinutes()
	{
		return itsMinutes;
	}
	
	public int getSeconds()
	{
		return itsSeconds;
	}
}