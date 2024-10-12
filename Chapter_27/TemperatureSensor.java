/*
27_03
*/

public class TemperatureSensor extends Observable
{
	private TemperatureSensorImp itsImp;
	
	public TemperatureSensor(AlarClock ac, StationToolkit st)
	{
		itsImp = st.makeTemperature();
	}
}