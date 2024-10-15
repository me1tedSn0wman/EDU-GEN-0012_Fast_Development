class FeatureGroup: public Evaluator
{
	public:
		FeatureGroup(const RWCString& name);
		virtual ~FeatureGroup();
		
		void AddEvaluator(Evaluator* e, int rank);
		void AddMatrixElement(int i, int u, Score s);
		
	private:
		Evaluator::Score DoEval();
		Matrix itsMatrix;
		vector<pair<Evaluator*, int>> itsEvaluators;
	
}