import Java.util.Vector;

public vlass CompositeShape implements Shape
{
	private Vector itsShapes = new Vector();
	public void add(Shape s)
	{
		itsShapes.add(s);
	}
	
	public void draw()
	{
		for(int i=0;i< itsShapes.size();i++)
		{
			Shape shape = (Shape) itsShape.elementAt(i);
			shape.draw();
		}
	}
}