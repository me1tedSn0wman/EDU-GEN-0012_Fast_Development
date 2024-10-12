public class AddItemTransaction extends Transaction
{
	public void addItem(int orderId, string sku, int qty)
	{
		Statement s = itsConnection.CreateStatement();
		s.executeUpdate("Insert into items values("
		 + orderId + "," + sku + "," +qty + ")");
		)
	}
	
}