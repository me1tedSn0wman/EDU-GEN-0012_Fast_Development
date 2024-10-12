/*
26_33
*/

#ifndef STAIRWAYTOHEACENPERSISTENTASSEMBLY_H
#define STAIRWAYTOHEACENPERSISTENTASSEMBLY_H

#include "assembly.h"
#include "persistentProduct.h"

class PersistentAssembly : public Assembly, public PersistentProduct
{
	public:
		PersistentAssembly(const string& name,
						   const string& assyCode);
		virtual ~PersistentAssembly();
	
	protected:
		virtual void writeFields(ostream& s) const;
		
	private:
		virtual void writeHeader(ostream& s) const;
		virtual void writeFooter(ostream& s) const;
};
#endif