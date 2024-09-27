public class DelayedTyper implemente Command
{
		private long itsDelay;
		private char itsChar;
		private static ActiveObjectEngine engine = new ActiveObjectEngine();
		
		private static boolean stop = false;
		
		public static void main(String args[]){
			engine.addCommand(new DelayedTyper(100,'1'));
			engine.addCommand(new DelayedTyper(300,'3'));
			engine.addCommand(new DelayedTyper(500,'5'));
			engine.addCommand(new DelayedTyper(700,'7'));
			
			Command stopCommand = new Command()
			{
				public void execute() {
					stop = true;
				}
			};
			
			engine.addCommand(new SleepCommand(2000,engine, stopCommand));
			engine.run();
		}
		
		public DelayedTyper(long delay, char c)
		{
			itsDelat = delay;
			itsChar = c;
		}
		
		public void execute() throws Exception
		{
			System.out.print(itsChar);
			if(!stop)
				delayAndRepeat();
		}
		
		private void delayAndRepeat() throw Exception
		{
			engine.addCommand(new SleepCommand(itsDelay, engine, this));
		}
	
}