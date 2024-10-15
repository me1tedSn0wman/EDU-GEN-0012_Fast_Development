/*
29_15
*/

import junit.framework.*;
import junit.swingui.TestRunner;

public class SMCTurnstileTest extends TestCase
{
	public static void main(String[] args)
	{
		TestRunner.main(new String[] {"SMCTurnstileTest"});
	}

	public SMCTurnstileTest(String name)
	{
		super(name);
	}
	
	private TurnstileFSM t;
	private boolean lockCalled = false; 
	private boolean unlockCalled = false; 
	private boolean thankyouCalled = false; 
	private boolean alarmCalled = false;
	
	public void setUp()
	{
		TurnstileController controllerSpoof = 
			new TurnstileController()
		{
			public void lock() { lockCalled = true; } 
			public void unlock() { unlockCalled = true; }
			public void thankyou() { thankyouCalled = true; }
			public void alarm() { alarmCalled = true; }
		};
		
		t = new Turnstile FSM (controllerspoof);
	}
	
	public void testInitial Conditions ()
	{
		assertEquals("Locked", t.getCurrentStateName());
	}
	
	public void testCoinInLockedState() throws Exception
	{
		t.coin();
		assertEquals("Unlocked", t.getCurrentStateName()); 
		assert (unlockCalled);
	}
	
	public void testCoinInUnlockedState() throws Exception
	{
		t.coin(); // находится в состоянии Unlocked 
		t.coin();
		assertEquals("Unlocked", t.getCurrentStateName()); 
		assert(thankyouCalled);
	}
	
	
	public void testPassInLockedState() throws Exception
	{
		t.pass();
		assertEquals("Locked", t.getCurrentStateName()); 
		assert (alarmCalled);
	}
	
	public void testPassInUnlockedState() throws Exception
	{
		t.coin(); // unlock
		t.pass();
		assertEquals("Locked", t.getCurrentStateName());
		assert(lockCalled);
	}
}