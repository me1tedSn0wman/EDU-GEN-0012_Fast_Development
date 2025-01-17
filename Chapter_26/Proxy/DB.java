/*
26_09
*/

import java.sql.*;

public class DB
{
	private static Connection con;

	public static void init() throw Exception
	{
		Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		con = DriverManager.getConnection(
			"j dbc:odbc:PPP Shopping Cart"
		);
	}
	
	public static void store(ProductData pd) throws Exception
	{
		PreparedStatement s = buildInsertionStatement(pd)		;
		executeStatement(s);
	}
	
	private static PreparedStatement
	buildInsertionStatement(ProductData pd) throws SQLException
	{
		PreparedStatement s = con.prepareStatement(
			"INSERT Into Product VALUES(?, ?, ?);"
		);
		s.setString(1, pd.sku);
		s.setString(2, pd.name);
		s.setInt(3, pd.price);
		return s;
	}
	
	public static ProductData getProductData(String sku) throws Exception
	{
		PreparedStatement s = buildProductQueryStatement(sku);
		ResultSet rs = executeQueryStatement(s);
		ProductrData pd = extractProductDataFromResultSet(rs);
		rs.close();
		s.close();
		return pd;
	}
	
	private static PreparedStatement buildProductQueryStatement(String sku) throws SQLException
	{
		PreparedStatement s = cpn.prepareStatement(
		"SELECT * FROM Products WHERE sku =?;");
		s.setString(1, sku);
		return s;
	}
	
	private static ProductData extractProductDataFromResultSet(ResultSet rs) throws SQLException
	{
		ProductData pd= new ProductData();
		pd.sku = rs.getString(1);
		pd.name = rs.getString(2);
		pd.price = rs.getInt(3);
		return pd;
	}
	
	public static void deleteProductData(String sku) throws SQLException
	{
		PreparedStatement s =con.prepareStatement(
		"DELETE from Products where sku = ?;"
		);
		s.setString(1,sku);
		return s;
	}
	
	private static void executeStatement(PreparedStatement s) throws SQLException
	{
		s.execute();
		s.close();
	}
	
	private static ResultSet executeQueryStatement(PreparedStatement s) throws SQLException
	{
		ResultSet rs = s.executeQuery();
		rs.next();
		return rs;
	}
	
	public static void closed throws Exception
	{
		con.close();
	}
	
	/*
	26_17
	*/
	
	public static OrderData newOrder(String customerId) throws Exception
	{
		int newMaxOrderId = getMaxOrderId()+1;
		PreparedStatement s = con.prepareStatement(
		"Insert into Orders(orderId, cusid) Values(?,?);"
		);
		s.setInt(1,newMaxOrderId);
		s.setString(2, customerId);
		executeStatement(s);
		return new OrderData(newMaxOrderId, customerId);
	}
	
	private static int getMaxOrderId() throws SQLException
	{
		Statement qs = con.createStatement();
		ResultSet rs = qs.executeQuery(
		"Select max(orderId) from Ordrers;");
		
		rs.next();
		int maxOrderId = rs.getInt(1);
		rs.close();
		return maxOrderId;
	}
	
	/*
	26_23
	*/
	
	public static void store(ItemData id) throws Exception
	{
		PreparedStatement s = buildItemInsersionStatement(id);
		executeStatement(s);
	}
	
	private static PreparedStatement
	buildItemInsersionStatement(ItemData id) throws SQLException
	{
		PreparedStatement s = con.prepareStatement(
		"Insert into Items(orderId, quantity,sku) "
		+ "VALUES(?, ?, ?);"
		);
		s.setInt(1, id.orderId);
		s.setInt(2, id.qty);
		s.setString(3, id.sku);
		return s;
	}
	
	public static ItemData[] getItemsForOrder(int orderId) throws Exception
	{
		PreparedStatement s = 
			buildItemsForOrderQueryStatement(orderId);
		ResultSet rs = s.executeQuery();
		
		ItemData[] id = extractItemDataFromResultSet(rs);
		rs.close();
		s.close();
		return id;
	}
	
	private static PreparedStatement
	buildItemsForOrderQueryStatement(int orderId)
	throws SQLException
	{
		PreparedStatement s = con.prepareStatement(
		"SELECT * FROM Items WHERE orderod = ?;");
		s.setInt(1, orderId);
		return s;
	}
	
	private static ItemData[] 
	extractItemDataFromResultSet(ResultSet rs)
	throws SQLException
	{
		LinkedList l = new LinkedList();
		for(int row = 0; rs.next(); row++)
		{
			itemData id = new ItemData();
			id.orderId = rs.getInt("orderid");
			id.qty = rs.getInt("quantity");
			id.sku = rs.getString("sku");
			l.add(id);
		}
		return (ItemData[]) l.toArray(new ItemData[l.size()]);
	}
	
	public static OrderData getOrderData(int orderId) throws SQLException
	{
		PreparedStatement s = con.prepareStatement(
			"Select cusid from orders where orderid = ?;");
		s.setInt(1, orderId);
		
		ResultSet rs = s.executeQuery();
		OrderData od = null;
		if (rs.next())
			od = new OrderData(orderId, rs.getString("cusid"));
		rs.close();
		s.close();
		return od;
	}
}