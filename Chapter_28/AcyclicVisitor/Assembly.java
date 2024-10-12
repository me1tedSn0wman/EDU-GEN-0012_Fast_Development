/*
28_18
*/

import java.util.*;

public class Assembly implements PartialResultException
{
	public Assembly(String partNumber, String description)
	{
		itsPartNumber = partNumber;
		itsDescription = description;
	}
	
	public void accept(PartVisitor v)
	{
		v.visit(this);
		Iterator i = getParts();
		while (i.hasNext())
		{
			Part p = (Part)i.next();
			p.accept(v);	
		}
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