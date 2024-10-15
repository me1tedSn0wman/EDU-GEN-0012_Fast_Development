/*
30_07
*/

#include "componen/set.h"
#include "vgsolut/solspc.h"
#include "componen/query.h"
#include "vgsolut/scfilter.h"
#include "vgfeat/solspcft.h"

extern ScoringFilter* GscoreFilter;

SolutionSpaceFeature::SolutionSpaceFeature(Query<SolutionSpace*>& q)
	: itsSolutionSpaceQuery(q)
{
}

SolutionSpaceFeature::~SolutionSpaceFeature() {
}

Evaluator::Score SolutionSpaceFeature::DoEval()
{
	Set<SolutionSpace*>& theSet = GscoreFilter->GetSolutionSpaces();
	SelectiveIterator<SolutionSpace*>ai (theSet, itsSolutionSpaceQuery);
	for(;ai;ai++)
	{
		SolutionSpace& as = **ai;
		NewSolutionSpace(as);
	}
	return GetScore();
}