/*
28_01
*/

public interface Modem
{
	public void dial(String pno);
	public void hangup();
	public void send(char c);
	public char recv();
	public void accept(ModemVisitor v);
}