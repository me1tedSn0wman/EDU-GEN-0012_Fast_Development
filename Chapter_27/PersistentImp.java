package api;
import Java.io.Serializable;
import Java.util.AbstractList;

public interface PersistentImp
{
	void store(String name, Serializable obj);
	Object retrieve(String name);
	AbstractList directory(String regExp);
};