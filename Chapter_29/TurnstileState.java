/*
29_06
*/

interface TurnstileState
{
	void coin(Turnstile t);
	void pass(Turnstile t);
}

class LockedTurnstileState implements TurnstileState
{
	public void coin(Turnstile t)
	{
		t.setUnlocked();
		t.unlock();
	}
	
	public void pass(Turnstile t)
	{
		t.alarm();
	}
}

class UnlockedTurnstileState implements TurnstileState
{
	public void coin(Turnstile t)
	{
		t.thankyou();
	}
	
	public void pass(Turnstile t)
	{
		t.setLocked();
		t.lock();
	}
	
}