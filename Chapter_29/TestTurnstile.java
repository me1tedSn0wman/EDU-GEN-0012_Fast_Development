package com.objectmentor.PPP.Patterns.State.turnstile;

import junit.framework.*;
import junit.swingui.TestRunner;

public class TestTurnstile extends TestCase
{
	public static void main(String[] args)
	{
		TestRunner.main( new String[] {"TestTurnstile"});
	}
	
	public TestTurnstile(String name)
	{
		super(name);
	}
	
	private Turnstile t;
	private boolean lockCalled = false;
	private boolean unlockCalled = false;
	private boolean thankyouCalled = false;
	private boolean alarmCalled = false;
	
	public void setUp()
	{
		TurnsileController controllerSpoof = new Turnstilecontroller()
		{
			public void lock() { lockCalled = true; }
			public void unlock() { unlockCalled = true; }
			public void thankyou() { thankyouCalled = true; }
			public void alarm() { alarmCalled = true; }
		}
		
		t = new Turnstile(controllerSpoof);
	}
	
	public void testInitialConditions()
	{
		assertEquals(Turnstile.LOCKED, t.state);
	}
	
	public void testCoinInLockedState()
	{
		t.state = Turnstile.LOCKED;
		t.event(Turnstile.COIN);
		assertEquals(Turnstile.UNLOCKED, t.state);
		assert(unlockCalled);
	}
	
	public void testCoinInUnlockedState()
	{
		t.state = Turnstile.UNLOCKED;
		t.event(Turnstile.COIN);
		assertEquals(Turnstile.UNLOCKED, t.state);
		assert(thankyouCalled);
	}
	
	public void testPassInLockedState()
	{
		t.state = Turnstile.LOCKED;
		t.event(Turnstile.PASS);
		assertEquals(Turnstile.LOCKED, t.state);
		assert(alarmCalled);
	}
	
	public void testPassInUnlockedState()
	{
		t.state = Turnstile.UNLOCKED;
		t.event(Turnstile.PASS);
		assertEquals(Turnstile.LOCKED, t.state);
		assert(lockCalled);
	}
}