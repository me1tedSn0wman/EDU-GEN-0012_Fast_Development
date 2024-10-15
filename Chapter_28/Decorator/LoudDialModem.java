/*
28_26
*/

public class LoudDialModem implements Modem
{
	public LoudDialModem(Modem m)
	{
		itsModem = m;		
	}
	
	public void dial(String pno)
	{
		itsModem.setSpeakerVolume(10);
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
	
	private Modem itsModem;
	
}