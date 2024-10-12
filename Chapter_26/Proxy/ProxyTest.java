/*
26_10
*/

import junit.framework.*;
import junit.swingui.TestRunner;

public static ProxyTest extends TestCase
{
	public static void main(String[] args)
	{
		TestRynner.main(new String[]{"ProxyTest"});
	}
	
	public ProxyTest(String name)
	{
		super(name);
	}
	
	public void setUp() throws Exception
	{
		DB.init();
		ProductData pd= new ProductData();
		pd.sku = "ProxyTest1";
		pd.name = "ProxyTestName1";
		pd.price = 456;
		DB.store(pd);
	}
	
	public void tearDown() throws Exception
	{
		DB.deleteProductData("ProxyTest1");
		DB.close();
	}
	
	public void testProductProxy() throws Exception
	{
		Product p = new ProductProxy("ProxyTest1");
		assertEquals(456, p.getPrice);
		assertEquals("ProxyTestName1", p.getName());
		assertEquals("ProxyTest1", p.getSky());		
	}
	
	/*
	26_14
	*/
	
	public static testOrderProxyTotal() throws Exception
	{
		DB.store(new ProductData("Wheaties", 349, "wheaties"));
		DB.store(new ProductData("Crest", 258, "crest"));
		ProductProxy wheaties = new ProductProxy("wheaties");
		ProductProxy crest = new ProductProxy("crest");
		
		OrderData od = DB.newOrder("testOrderProxy");
		OrderProxy order = new OrderProxy(od.orderId);
		
		order.addItem(crest,1);
		order.addItem(wheaties,2);
		assertEquals(956, order.total());
		
	}
}