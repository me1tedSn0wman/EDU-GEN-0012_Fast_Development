public class ProductImp implements ProductImp
{
	private int itsPrice;
	private String itsName;
	private String itsSku;
	
	public ProductImp(string sku, String name, int price)
	{
		itsPrice = price;
		itsName = name;
		itsSku = sku;
	}
	
	public int getPrice()
	{
		return itsPrice;		
	}
	
	public String getName()
	{
		return itsName;		
	}
	
	public String getSku()
	{
		return itsSku;
	}
}