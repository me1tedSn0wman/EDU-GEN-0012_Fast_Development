public class SleepCommand implements Command
{
	private Command wakeUpCommand = null;
	private AciveObjectEngine engine = null;
	private long sleepTime = 0;
	private long startTime = 0;
	private boolean started = false;
	
	public SleepCommand(long milliseconds, ActiveObjectEngine eng, Command wakeUpCommand)
	{
		sleepTime = milliseconds;
		engine = eng;
		this.wakeUpCommand = wakeUpCommand;
	}
	
	public void execute() throws Exception
	{
		long currentTime = System.currentTimeMillis();
		if(!started){
			started = true;
			startTime = currentTime;
			enfine.addCommand(this)
		}
		else if ((currentTime - startTime)< sleepTime)
		{
			engine.addCommand(this);
		}
		else
		{
			engine.addCommand(wakeupCommand);
		}		
	}
}