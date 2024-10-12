/*
28_06
*/

public class UnixModemConfigurator implements ModemVisitor
{
	public void visit(HayesModem m)
	{
		m.configurationString = "&sl=4&D=3";
	}
	
	public void visit(ZoomModem m)
	{
		m.configurationValue = 42;		
	}
	
	public void visit(ErnieModem m)
	{
		m.internalPattern = "C is too slow";
	}
}