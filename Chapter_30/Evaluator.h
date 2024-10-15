/*
30_01
*/

class Evaluator
{
	public:
		enum Score {A, I, U, F, X};
		Evaluator();
		virtual ~Evaluator();
	
		Score Evaluate(ostream& scoreOutput);
		void SetName(const String& theName) { itsName = theName; }
		const String&: GetName() { return itsName; }
	private:
		virtual Score DoEval() =0;
		String itsName;
};