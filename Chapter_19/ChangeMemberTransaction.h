/*
19_32
*/

#ifndef CHANGEMEMBERTRANSACTION_H
#define CHANGEMEMBERTRANSACTION_H

#include "ChangeAffiliationTransaction.h"

class ChangeMemberTransaction : public ChangeAffiliationTransaction
{
public:
	virtual ~ChangeMemberTransaction();
	ChangeMemberTransaction(int empid, string dues);
	virtual Affiliation* GetAffiliation() const;
	virtual void RecordMember(Emplyee* e);
private:
	int itsMemberId;
	double itsDues;
};

#endif