/*
26_05
*/
/*
public class Product
{
	private int itsPrice;
	
	public Product(String name, int price)
	{
		itsPrice = price;
	}
	
	public int getPrice()
	{
		return itsPrice;		
	}	
}
*/


/*
26_11
*/
public interface Product
{
	public int getPrice() throws Exception;
	public String getName() throws Exception;
	public String getSku() throws Exception;
}