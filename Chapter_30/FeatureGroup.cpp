/*
30_05
*/

Evaluator::Score FeatureGroup::DoEval()
{
	int sumU, sumI;
	sumU = sumI = 0;
	Evaluator::Score s, rtnScore;
	Vector<Pair<Evaluator*, int>>::iterator ei;
	ei = itsEvaluators.begin();
	for(;ei != itsEvaluators.end(); ei++)
	{
		Evaluator* e = (*ei).first;
		int rank = (*ei).second;
		
		s = e.Evaluate(outputStream);
		
		switch(s)
		{
			case I:
				sumI += rank;
			break;
			case U:
				sumU += rank;
			break;
		}
	}
	rtnScore = itsMatrix.GetScore(sumI, sumU);
	return rtnScore;
}