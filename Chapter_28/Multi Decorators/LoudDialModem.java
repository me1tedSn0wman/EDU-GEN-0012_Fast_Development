/*
28_29
*/

public class LoudDialModem extends ModemDecorator
{
	public LoudDialModem(Modem m)
	{
		super(m);
	}
	
	public void dial(String pno)
	{
		getModem().setSpeakerVolume(10);
		getModem().dial(pno);
	}
}