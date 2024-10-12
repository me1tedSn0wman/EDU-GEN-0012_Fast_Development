/*
28_17
*/

public interface Part
{
	public String getPartNumber();
	public String getDescription();
	public void accept(PartVisitor v);
}