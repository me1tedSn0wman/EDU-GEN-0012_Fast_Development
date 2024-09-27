public void testNull() throws Exception
{
	Employee e = DB.getEmployee("Bob");
	if(e.isTimeToPay(new Date()))
		fail();
	assertEquals(Employee.NULL, e);	
}