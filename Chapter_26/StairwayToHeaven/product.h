/*
26_25
*/

#ifndef STAIRSTOHEAVENPRODUCT_H
#define STAIRSTOHEAVENPRODUCT_H

#include <string>
class Product
{
	public:
		Product(const string& name);
		virtual ~Product();
		const string& getName() const {return itsName;}
	private:
		string itsName;
};
#endif