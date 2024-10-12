/*
28_16
*/

import junit.framework.*;

public class TestModemVisitor extends TestCase
{
	public TestModemVisitor(String name)
	{
		super(name);
	}
	
	private UnixModemConfigurator();
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
		assertEquals("&sl=4&D=3", h.configurationString);
	}
	
	public void testZoomForUnix()
	{
		z.accept(v);
		assertEquals(42, z.configurationValue);
	}
	
	public void testErnieFoxUnix()
	{
		e.accept(v);
		assertEquals("C is too slow", e.internalPattern);
		
	}
}
