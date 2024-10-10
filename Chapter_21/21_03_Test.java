public void testCreateCircle() throws Exception
{
	Shape s = factory.make("Circle");
	assert(s instanceof Circle);
}