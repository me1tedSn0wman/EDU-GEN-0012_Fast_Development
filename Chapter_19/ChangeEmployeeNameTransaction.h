/*
19_22
*/

#ifndef CHANGEEMPLYEENAMETRANSACTION_H
#define CHANGEEMPLYEENAMETRANSACTION_H

#include "ChangeEmployeeTransaction.h"
#include <string>

class ChangeEmployeeNameTransaction : public ChangeEmployeeTransaction {
public:
	virtual ~ChangeEmployeeNameTransaction();
	ChangeEmployeeNameTransaction(int empid, string name);
	virtual void Change(Employee& e);
private:
	string itsName;
};

#endif