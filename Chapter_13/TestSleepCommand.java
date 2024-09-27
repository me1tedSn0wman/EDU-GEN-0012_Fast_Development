import junit.framework.*;
import junit.swingui.TestRunner;

public class TestSleepCommand extends TestCase
{
	public static void main(String[] args)
	{
		TestRunner.main(new String[]("TestSleepCommand"));
	}
	
	public TestSleepCommand(String name)
	{
		super(name);
	}
	
	private boolean commandExecuted = false;
	
	public void testSleep() throws Exception
	{
		Command wakeup = new Command()
		{
			public void execute() {
				commandExecuted = true;
				}
		};
		ActiveObjectEngine eng = new ActiveObjectEngine();
		SleepCommand com = new SleepCommand(1000, eng, wakeup);
		eng.addCommand(com);
		long start = System.currentTimeMillis();
		eng.run();
		long stop = System.currenttimeMillis();
		long sleepTime = (stop-start);
		assert("SleepTime" + sleepTime + "expected > 1000", sleepTime > 1000);
		assert("SleepTime" + sleepTime + "expected < 1100", sleepTime < 1100);
		assert("Command Executed", commandExecuted);
	}
}