/*
26_24
*/

void ProductPeesistemceTestCase::testWriteProduct()
{
	ostrstream s;
	Product * p = PersistentProduct("Cheerios");
	PersistentObject* po = dynamic_cast<PersistentObject*>(p);
	assert(po);
	po->write(s);
	char* writtenString = s.str();
	assert(strcmp("<PRODUCT><NAME>Cheerios</NAME></PRODUCT>",writtenString)==0);
}

void ProductPeesistemceTestCase::testWriteAssembly()
{
	ostrstream s;
	Assembly* a new PersistentAssemly("Wheaties", "7734");
	PersistentObject* po = dynamic_cast<PersistentObject*>(a);
	assert(po);
	po->write(s);
	char* writtenString = s.str();
	assert (strcmp("<ASSEMBLY><NAME>Wheaties</NAME><ASSYCODE>7734</ASSYCODE></ASSEMBLY>", writtemString)==0);
}