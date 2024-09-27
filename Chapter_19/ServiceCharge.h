#ifndef SERVICECHARGE_H
#define SERVICECHARGE_H

class ServiceCharge {
public:
	virtual ~ServiceCharge();
	ServiceCharge(long date, double amount);
	long GetDate() { return itsDate; }
	double GetAmount() { return itsAmount; }
private:
	long itsDate;
	double itsAmount;
};

#endif