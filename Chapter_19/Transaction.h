/*
19_1
*/

#indef TRANSACTION_H
#define TRANSACTIONS_H

class Transaction
{
	public:
	virtual ~Transaction();
	virtual void Execute() = 0;
};

#endif