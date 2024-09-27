public interface UserDatabase
{
	User readUser(String userName);
	writeUser(User user);
}