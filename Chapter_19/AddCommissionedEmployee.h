#ifndef ADDCOMMISIONEDEMPLOYEE_H
#define ADDCOMMISIONEDEMPLOYEE_H

#include "AddEmployeeTransaction.h"

class AddCommissionedEmployee : public AddEmployeeTransaction
{
public:
	virtual ~AddCommisionedEmployee();
	AddCommissionedEmployee(int empid, string name, string address, double salary, double commissionRate);
	PaymentClassification* GetClassification() const;
	PaymentSchedule* GetSchedule() const;
private:
	double itsSalary;
	double itsCommissionRate;
};

#endif // !ADDCOMMISIONEDEMPLOYEE_H
