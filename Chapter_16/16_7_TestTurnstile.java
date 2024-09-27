import juint.framework.*;

public class TestTurnstile extends TestCase
{
	public TestTurnstile(String name){
		super(name);
	}
	
	public void setUp()
	{
		Turnstile t = new Turnstile();
		t.reset();
	}
	
	public void testInit()
	{
		Turnstile t = new Turnstile();
		assert(t.locked());
		assert(!t.alarm());
	}
	
	public void testCoin()
	{
		Turnstile t = new Turnstile();
		t.coin();
		Turnstile tl = new Turnstile();
		assert(tl.locked());
		assert(!tl.alarm());
		assertEquals("coins", 1, tl.coins());
	}
	
	public void testTwoCoins()
	{
		Turnstile t = new Turnstile();
		
		t.coin();
		t.coin();
		
		Turnstile t1 = new Turnstile();
		assert("unlocked", !tl.locked());
		assertEquals("coins", 1, t1.coins());
		assertEquals("refunds", 1, t1.refunds());
		assert(!t1.alarm());
	}
	
	public void testPass()
	{
		Turnstile t = new Turnstile();
		t.pass();
		Turnstile t1 = new Turnstile();
		assert("alarm", t1.alarm());
		assert("locked", t1.locked());
	}
	
	public void testCancelAlarm()
	{
		Turnstile t = new Turnstile();
		t.pass();
		t.coin();
		Turnstile t1 = new Turnstile();
		assert("alarm", !t1.alarm());
		assert("locked", !t1.locked());
		assertEquals("coin", 1, t1.coins());
		assertEquals("refund", 0, t1.refunds());
	}
	
	public void testTwoOperations()
	{
		Turnstile t = new Turnstile();
		t.coin();
		t.pass();
		t.coin();
		assert("unlocked", !t.locked());
		assertEquals("coins", 2, t.coins());
		t.pass();
		assert("locked", t.locked());
	}
}