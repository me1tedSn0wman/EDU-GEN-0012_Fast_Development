import junit.framework.*;

//public class ClockDriverTest extends TestCase
public class ObserverTest extends TestCase
{
	private MockTimeSource source;
	private MockTimeSink sink;
	
	public ClockDriverTest(String name)
	{
		super(name);
	}
	
	public void setUp()
	{
		source = new MockTimeSource();
		sink = new MockTimeSink();
		source.registerObserver(sink);
	}
	
	private void assertSinkEquals(MockTimeSink sink, int hours, int minutes, int seconds)
	{
		assertEquals(hours, sink.getHours());
		assertEquals(minutes, sink.getMinutes());
		assertEquals(seconds, sink.getSeconds());
	}
	
	public void testTimeChange()
	{
		source.setTime(3,4,5);
		assertSinkEquals(sink,3,4,5);
		
		source.setTime(7,8,9);
		assertSinkEquals(sink,7,8,9);
	}
	
	public void testMultipleSink()
	{
		MockTimeSink sink2 = new MockTimeSink();
		source.registerObserver(sink2);
		
		source.setTime(12,13,14);
		assertSinkEquals(sink,12,13,14);
		assertSinkEquals(sink2,12,13,14);
		
	}
	
	/*
	public void testTimeChange()
	{
		MockTimeSource source = new MockTimeSource();
		MockTimeSink sink = new MockTimeSink();
//		ClockDriver driver = new ClockDriver(source, sink);
		source.setObserver(sink);
		
		source.setTime(3,4,5);
		assertEquals(3, sink.getHours());
		assertEquals(4, sink.getMinutes());
		assertEquals(5, sink.getSeconds());
		
		source.setTime(7,8,9);
		assertEquals(7, sink.getHours());
		assertEquals(8, sink.getMinutes());
		assertEquals(9, sink.getSeconds());
	}
	*/
	
	
	
}