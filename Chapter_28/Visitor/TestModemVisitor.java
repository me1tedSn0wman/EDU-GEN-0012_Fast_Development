/*
28_07
*/

import junit.framework.*;

public class TestModemVisitor extends TestCase
{
	public TestModemVisitor(String name)
	{
		super(name);
	}
	
	private UnixModemConfigurator v;
	private HayesModem h;
	private ZoomModem z;
	private ErnieModem e;
	
	public void setUp()
	{
		v = new UnixModemConfigurator();
		h = new HayesModem();
		z = new ZoomModem();
		e = new ErnieModem();
	}
	
	public void testHayesForUnix()
	{
		h.accept(v);
		assertEquals("&sl=4&D=3", h.configurationValue);
	}
	
	public void testZoomForUnix()
	{
		z.accept(v);
		assertEquals(42, z.configurationValue);
	}
	
	public void testErnieForUnix()
	{
		e.accept(v);
		assertEquals("C is too slow", e.internalPattern);
	}
}