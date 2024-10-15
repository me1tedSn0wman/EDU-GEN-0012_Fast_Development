/*
29_02
*/

package com.objectmentor.PPP.Patterns.State.turnstile;

public interface TurnstileController
{
	public void lock();
	public void unlock();
	public void thankyou();
	public void alarm();
	
}