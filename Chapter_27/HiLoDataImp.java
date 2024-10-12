public class HiLoDataImp implements HiLoData, Java.io.Serializable
{
	public HiLoDataImp(StationToolkit st, String type, Date theDate, double init, long initTime)
	{
		itsPI = st.getPersistentImp();
		itsType = type;
		itsStorageKey = calculateStorageKey(theDate);
		try{
			HiLoData t = (HiLoData)itsPI.retrive(itsStorageKey);
			itsHighTime = t.getHighTime();
			itsLowTime = t.getLowTime();
			itsHighValue = t.getHighValue();
			itsLowValue = t.getLowValue();
			currentReading(init, initTime);
		}
		catch (RetrieveException re)
		{
			itsHighValue = itsLowValue = init;
			itsHighTime = itsLowTime = initTime;
		}
	}
	
	public long getHighTime() { return itsHighTime; }
	public long getLowTime { return itsLowTime; }
	public double getHighValue() { return itsHighValue; }
	public double getLowValue() { return itsLowValue; }
	
	
	public void currentReading(double current, long time)
	{
		if (current > itsHighValue)
		{
			itsHighValue = current;
			itsHighTime = time;
			store();
		}
		else if (current < itsLowValue)
		{
			itsLowValue = current;
			itsLowTime = time;
			store();
			
		}
	}
	
	public void newDay(double initial, long time)
	{
		store();
		
		itsLowValue = itsHighValue = initial;
		itsLowTime = itsHighTime = time;
		
		itsStorageKey = calculateStorageKey(new Date());
		store();
	}
	
	private store()
	{
		try
		{
			itsPI.store(itsStorageKey, this);
		}
		catch (StoreException)
		{
			
		}
	}
	
	private String calculateStorageKey(Date d)
	{
		SimpleDateFormat df = new SimpleDateFormat("MMddyyyy");
		return(itsType + "HiLo" + df.format(d));
	}
	
	private double itsLowValue;
	private long itsLowTime;
	private double itsHighValue;
	private long itsHighTime;
	private String itsType;
	
	
	transient private String itsStorageKey;
	transient private api.PersistentIm itsPI;
	
}