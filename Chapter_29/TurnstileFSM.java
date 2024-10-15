/*
29_10
*/

public class TurnstileFSM extends Turnstile
{
	private TurnstileController controller;
	public TurnstileFSM(TurnstileController controller)
	{
		this.controller = controller;	
	}
	
	public void lock()
	{
		controller.lock();
	}
	
	public void unlock()
	{
		controller.unlock();
	}
	
	
	public void thankyou()
	{
		controller.thankyou();
	}
	
	public void alarm()
	{
		controller.alarm();
	}
	
}