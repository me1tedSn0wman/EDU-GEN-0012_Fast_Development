/*
30_06
*/

#ifndef FEATURE_SOLUTION_SPACE_FEATURE_H
#define FEATURE_SOLUTION_SPACE_FEATURE_H

#include "scoring/eval.h"

template <class T> class Query;

class SolutionSpace;

class SolutionSpaceFeature : public Evaluator
{
	public:
		SolutionSpaceFeature(Query<SolutionSpace*>&);
		virtual ~SolutionSpaceFeature();
		virtual Evaluator::Score DoEval();
		virtual void NewSolutionSpace(xonst SolutionSpace&) = 0;
		virtual Evaluator::Score GetScore() = 0;
	private:
		SolutionSpaceFeature(const SolutionSpaceFeature&);
		SolutionSpaceFeature& operator = (const SolutionSpaceFeature&);
		Query<SolutionSpace*>& itsSolutionSpaceQuery;
};
#endif