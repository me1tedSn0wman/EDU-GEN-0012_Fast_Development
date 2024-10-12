/*
27_01
27_02
27_04
27_05
*/

/*
public class WeatherStation
{
	public static void main(String[] args)
	{
		try
		{
			Class tkClass = Class.forName(args[0]);
			StationToolkit st = 
				(StationToolkit) tkClass.newInstance();
		
			AlarmClock ac = new AlarmClock(st);
		
			TemperatureSensor ts = new TemperatureSensor(
				ac,
				st
			);
		
			BarometricPressureSensor bps = new BarometricPressureSensor(
				ac,
				st
			);
			
			BarometricPressureTrend bpt = new BarometricPressureTrend(
				bps
			);
		}
		catch(Exception e)
		{
		}
	}
}
*/

/*
27_06
*/

public class Weatherstation
{
	public Weatherstation(String tkName)
	{
		try
		{
			Class tkClass = Class.forName(tkName);
			StationToolkit st = 
				(StationToolkit) tkClass.newInstance();
			
			AlarmClock ac = new AlarmClock(st);
			
			TemperatureSensor ts = new TemperatureSensor(
				ac,
				st
			);
			
			BarometricPressureSensor bps = new BarometricPressureSensor(
				ac,
				st
			);
				
			BarometricPressureTrend bpt = new BarometricPressureTrend(
				bps
				);
		}
		catch(Exception e)
		{
		}
	}
	
	public void addTempObserver(Observer o)
	{
		itsTS.addObserver(o);
	}
	
	public void addBPObserver(Observer o)
	{
		itsBPS.addObserver(o);	
	}
	
	public void addBPTrendObserver(Observer o)
	{
		itsBPT.addObserver(o);
	}
	
	private TemperatureSensor itsTS;
	private BarometricPressureSensor itsBPS;
	private BarometricPressureTrend itsBPT;
}