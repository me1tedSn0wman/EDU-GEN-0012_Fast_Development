/*
28_04
*/

public class ZoomModem implements Modem
{
	public void dial(String pno) {}
	
	public void hangup() {}
	
	public void send(char c) {}
	
	public char recv() { return 0; }
	
	public void assept(ModemVisitor v) { v.visit(this); }
	
	int configurationValue = 0;	
}