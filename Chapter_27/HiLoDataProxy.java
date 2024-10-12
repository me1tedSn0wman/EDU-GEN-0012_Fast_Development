/*
27_09
*/

class HiLoDataProzy implements HiLoDataProzy
{
	public boolean currentReading(double current, long time)
	{
		boolean change;
		change = itsImp.currentReading(current, time);
		if(change)
			store();
		return change;
	}
	
	public void newDay(double initial, long time)
	{
		store();
		itsImp.newDay(initial, time);
		calculateStorageKey(new Date(time));
		store();
	}
	
	private HiLoDataImp itsImp;
}

class HiLoDataImp implements HiLoData, java.io.Serializable
{
	public boolean currentReading(Double current, long time)
	{
		boolean changed = false;
		if(current > itsHighValue)
		{
			itsHighValue = current;
			itsHighTime = time;
			changed = true;	
		}
		else if (current < itsLowValue)
		{
			itsLowValue = current;
			itsLowTime = time;
			changed = true;
		}
		return changed;
	}
	
	public void newDay(double initial, long time)
	{
		itsHighTime = itsLowTime = time;
		itsHighValue = itsLowValue = initial;
	}
}