/*
28_33
*/

public class PiecePart extends PartialResultException
{
	public PiecePart(String partNumber, String description, double cost)
	{
		itsPartNumber = partNumber;
		itsDescription = description;
		itsCost = cost;
		addExtension("CSV", new CSVPiecePartExtension(this));
		addExtension("XML", new XMLPiecePartExtension(this));
		
	}
	
	public String getPartNumber()
	{
		return itsPartNumber;
	}
	
	public String getDescription()
	{
		return itsDescription;
	}
	
	public double getCost()
	{
		return itsCost;		
	}
	
	private String itsPartNumber;
	private String itsDescription;
	private double itsCost;
}