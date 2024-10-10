public class Order
{
	private Vector itsItems = new Vector();
	
	public void addItem(Product p, int qty)
	{
		Item item = new Item(p,qty);
		itsItems.add(item);
	}
}