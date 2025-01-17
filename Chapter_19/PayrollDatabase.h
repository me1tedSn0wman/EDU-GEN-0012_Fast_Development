/*
19_3
*/

#ifndef PAYROLLDATABASE_H
#define PAYROLLDATABASE_H

#include <map>

class Employee;

class PayrollDatabase
{
	public:
		virtual ~PayrollDatabase();
		Employee* GetEmployee(int empId);

		void AddEmployee(int empid, Employee*);
		void clear() {
			itsEmployees.clear();
		}
	private:
		map<int, Employee*> itsEmployees;
};
#endif
