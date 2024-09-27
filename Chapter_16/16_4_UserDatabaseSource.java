public class UserDatabaseSource implements UserDatabase
{
	private static UserDatabase theInstance = new UserDatabaseSource();
	
	public static UserDatabase instance()
	{
		return theInstance;
	}
	
	private UserDatabaseSource()
	
	public User readUser(String userName)
	{
		return null;
	}
	
	public void writeUser(User user)
	{
		
	}
}