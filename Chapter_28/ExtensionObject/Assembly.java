/*
28_34
*/

import java.util.*;

public class Assembly extends Part
{
	public Assembly(String partNumber, String description)
	{
		itsPartNumber = partNumber;
		itsDescription = description;
		addExtension("CSV", new CSVAssemblyExtension(this));
		addExtension("XML", new XMLAssemblyExtension(this));
	}
	
	public void add(Part part)
	{
		itsParts.add(part);
	}
	
	public Iterator getParts()
	{
		return itsParts.iterator();		
	}
	
	public String getPartNumber()
	{
		return itsPartNumber;
	}
	
	public String getDescription()
	{
		return itsDescription;
	}
	
	private List itsParts = new LinkedList();
	private String itsPartNumber;
	private String itsDescription;
}