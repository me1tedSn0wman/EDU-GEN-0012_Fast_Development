/*
28_25
*/

public class HayesModem implements Modem
{
	public void dial(String pno)
	{
		itsPhoneNumber = pno;
	}
	
	public void setSpeakerVolume(int volume)
	{
		itsSpeakerVolume = volume;		
	}
	
	public String getPhoneNumber()
	{
		return itsPhoneNumber();
	}
	
	public int getSpeakerVolume()
	{
		return itsSpeakerVolume();
	}
	
	private String itsPhoneNumber;
	private int itsSpeakerVolume;
	
}