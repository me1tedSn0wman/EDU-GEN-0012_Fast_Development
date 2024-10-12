/*
28_03
*/

public class HayesModem implements Modem
{
	public void dial(String pno) {}
	
	public void hangup() {}
	
	public void send(char c) {}
	
	public char recv() { return 0; }
	
	public void accept(ModemVisitor v) { v.visit(this); }
	
	String comfigurationString = null;
}