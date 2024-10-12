/*
26_13
*/

public class ProductProxy implements Product
{
	private String itsSku;
	public ProductProxy(string sku)
	{
		itsSku = sku;		
	}
	
	public int getPrice() throws Exception
	{
		ProductData pd = DB.getProductData(itsSku);
		return pd.price;
	}
	
	public String getNameO throws Exception
	{
		ProductData pd = DB.getProductData(itsSku);
		return pd.name;
	}
	
	public String getSku() throws Exception
	{
		return itsSku;		
	}
	
}