/*
28_31
*/

import java.util.*;

public abstract class Part
{
	HashMap itsExtensions = new HashMap();
	
	
	public abstract String getPartNumber();
	public abstract String getDescription();
	
	public void addExtension(String extensionType, PartExtension extension)
	{
		itsExtensions.put(extensionType, extension);
	}
	
	public PartExtension getExtension(String extensionType)
	{
		PartExtension pe = (PartExtension) itsExtensions.get(extensionType);
		if(pe = null)
			pe = new BadPartExtension();
		return pe;
	}
}