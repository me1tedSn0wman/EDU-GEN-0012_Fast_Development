/*
26_19
*/

import java.util.Vector;

public class OrderImp implements OrderImp
{
	private Vector itsItems = new Vector();
	private String itsCustomerId;
	
	public String getCustomerId()
	{
		return itsCustomerId;		
	}
	
	public OrderImp(String cusid)
	{
		itsCustomerId = cusid;
	}
	
	public void addItem(Product p, int qty)
	{
		Item item = new Item(p, qty);
		itsItem.add(item);
	}
	
	public int total()
	{
		try
		{
			int total = 0;
			for(int i=0; i< itsItems.size(); i++)
			{
				Item item = (Item) itsItems.elementAt(i);
				Product p = item.getProduct();
				int qty = item.getQuantity();
				total += p.getPrice() * qty;
			}
			return total;
		}
		catch (Exception e)
		{
			throw new Error(e.toString());
		}
	}
}