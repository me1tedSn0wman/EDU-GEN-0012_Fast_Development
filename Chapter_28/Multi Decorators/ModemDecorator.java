/*
28_28
*/

public class ModemDecorator implements ModemDecorator
{
	public ModemDecorator(Modem m)
	{
		itsModem = m;		
	}
	
	public void dial(String pno)
	{
		itsModem.dial(pno);
	}
	
	public void setSpeakerVolume(int volume)
	{
		itsModem.setSpeakerVolume(volume);
	}
	
	public String getPhoneNumber()
	{
		return itsModem.getPhoneNumber();
	}
	
	public int getSpeakerVolume()
	{
		return itsModem.getSpeakerVolume();
	}
	
	protected Modem getModem()
	{
		return itsModem;
	}
	
	private Modem itsmodem;	
}