/*
28_21
*/

public class ExplodedCostVisitor implements PartVisitor
{
	private double cost = 0;
	public double cost() { return cost; }
	public void visit(PiecePart p)
	{
		cost += p.getCost();
	}
	
	public void visit(Assembly a) {}
}