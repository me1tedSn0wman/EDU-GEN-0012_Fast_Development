/*
30_02
*/

Evaluatot::Score Evaluator::Evalate(ostrem&: o)
{
	static char scoreName[] = {'A', 'I', 'U', 'F', 'X'};
	o << itsName << " : ";
	score = DoEval();
	o << scoreName[score] << endl;
	return score;
	
}