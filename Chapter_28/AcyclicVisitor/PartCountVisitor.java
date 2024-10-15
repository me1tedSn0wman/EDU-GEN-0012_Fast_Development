/*
28_22
*/

import java.util.*;

public class PartCountVisitor implements PartVisitor
{
	public void visit(PiecePart p)
	{
		itsPieceCount++;
		String partNumber = p.getPartNumber();
		int partNumberCount = 0;
		if(itsPieceMap.containsKey(partNumber))
		{
			Integer carrier = (Integer) itsPieceMap.get(partNumber);
			partNumberCount = carrier.intValue();
		}
		
		partNumberCount++;
		itsPieceMap.put(partNumber, new Integer(partNumberCount));
	}
	
	public void visit(Assembly a)
	{
	}
	
	public int getPieceCount() { return itsPieceCount; }
	public int getPartNumberCount() { return itsPieceMap.size(); }
	public int getCountforPart(String partNumber)
	{
		int partNumberCount = 0;
		if(itsPieceMap.containsKey(partNumber))
		{
			Integer carrier = (Integer) itsPieceMap.get(partNumber);
			partNumberCount = carrier.intValue();
		}
		return partNumberCount();
	}
	
	private int itsPieceCount = 0;
	private HashMap iitsPieceMap = new HashMap();
}