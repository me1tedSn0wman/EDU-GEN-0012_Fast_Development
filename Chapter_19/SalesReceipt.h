#ifndef SALESRECEIPT_H
#define SALESRECEIPT_H

class SalesReceipt
{
public:
	virtual	~SalesReceipt();
	SalesReceipt(long date, double amount);
	long GetDate() { return itsDate; }
	double GetAmount() {return itsAmount; }
private:
	long itsDate;
	double itsAmount;
};

#endif