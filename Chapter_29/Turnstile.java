/*
29_01
*/

/*
package com.objectmentor.PPP.Patterns.State,turnstile;

public class Turnstile
{
	public static final int LOCKED =0;
	public static final int UNLOCKED =1;
	
	public static final int COIN =0;
	public static final int PASS =1;
	
	int state = LOCKED;
	
	private TurnstileControlled turnstileController;
	
	public Turnstile(TurnstileController action)
	{
		turnstileController = action;		
	}
	
	public void event(int event)	
	{
		switch(state)
		{
			case LOCKED:
				switch(event)
				{
					case COIN:
						state = UNLOCKED;
						turnstileController.unlock();
						break;
					case PASS:
						turnstileController.alarm();
						break;
				}
				break;
			case UNLOCKED:
				switch(event)
				{
					case COIN:
						turnstileController.thankyou();
						break;
					case PASS:
						state = LOCKED;
						turnstileController.lock();
						break;
				}
				break;
			
		}
		
	}
}
*/


/*
29_04
*/

/*
public Turnstile(TurnstileController action)
{
	turnstileController = action;
	addTransaction(LOCKED,		COIN, UNLOCKED,	unlock());
	addTransaction(LOCKED,		PASS, LOCKED,	alarm());
	addTransaction(UNLOCKED,	COIN, UNLOCKED,	thankyou());
	addTransaction(UNLOCKED,	PASS, UNLOCKED, unlock());
	
}
*/

/*
29_05
*/

/*
public void event(int event)
{
	for(int i=0; i<transitions.size(); i++){
		Transition transition = (Transition) transition.elementAt(i);
		if(state = transition.currentState && event == transition.event)
		{
			state = transition.newState;
			transition.action.execute();		
		}
	}
}
*/

/*
29_07
*/

/*
public class Turnstile
{
	private static TurnstileState lockedState
		= new LockedTurnstileState();
	private static TurnstileState unlcokedState 
		= new UnlockedTurnstileState();
		
	private TurnstileController turnstilecontroller;
	private TurnstileState state = lockedState;
	
	public Turnstile(TurnstileController action)
	{
		turnstileController = action;		
	}
	
	public void coin()
	{
		state.coin(this);
	}
	
	public void pass()
	{
		state.pass(this);
	}
	
	public void setLocked()
	{
		state = lockedState;
	}
	
	public void setUnlocked()
	{
		state = unlockedState;
	}
	
	public boolean isLocked()
	{
		return state == lockedState;
	}
	
	public boolean isUnlocked()
	{
		return state == unlockedState;
	}
	
	void thankyou()
	{
		turnstileController.thankyou();
	}
	
	void alarm()
	{
		turnstileController.alarm();
	}
	
	void lock()
	{
		turnstileController.lock();
	}
	
	void unlock()
	{
		turnstileController.unlock();		
	}
	
}
*/

/*
29_12
*/


import Java.util.Vector;

public class Turnstile {
	// Состояния
	public static final int LOCKED = 0; 
	public static final int UNLOCKED = 1;
	
	// События
	public static final int COIN = 0;
	public static final int PASS = 1;
	/*private*/ 
	int state= LOCKED;
	private TurnstileController turnstileController; 
	private Vector transitions = new Vector ();
	
	private interface Action
	{
		void execute();
	}
	
	private class Transition
	{
		public Transition (int currentState, int event, int newState, Action action)
		{
			this.currentState = currentState;
			this.event = event;
			this.newState = newState;
			this.action = action;
		}
		
		int currentState;
		int event;
		int newState;
		Action action;
	}
	
	public Turnstile (TurnstileController action)
	{
		turnstileController = action;
		addTransition (LOCKED, COIN, UNLOCKED, unlock() );
		addTransition (LOCKED, PASS, LOCKED, alarm() );
		addTransition (UNLOCKED, COIN, UNLOCKED, thankyou());
		addTransition (UNLOCKED, PASS, LOCKED, lock() );
	}

	private void addTransition (int currentState, int event, int newState, Action action)
	{
		transitions.add(
		new Transition (currentState, event, newState, action));
	}
 
	private Action lock()
	{
		return new Action() { public void execute() { doLock(); }};
	}

	private Action thankyou()
	{
		return new Action() { public void execute() (doThankyou(); } };
	}
	
	private Action alarm()
	{
		return new Action() { public void execute() (doAlarm();}};
	}

	private Action unlock()
	{
		return new Action() { public void execute() {doUnlock();)};
	}
	
	private void doUnlock()
	{
		turnstileController.unlock();
	}

	private void doLock()
	{
		turnstileController.lock();
	}
	
	private void doAlarm()
	{
		turnstileController.alarm();
	}
	
	private void doThankyou()
	{
		turnstileController.thankyou();
	}
	
	public void event (int event)
	{
		for (int i = 0; i < transitions.size(); i++)
		{
			Transition transition = (Transition) transitions.elementAt(i);
			if (state == transition.currentState &&
					event == transition.event)
					{
						state transition.newState;
						transition.action.execute();
					}
			
		}
		
	}
}


/*
29_13
*/


public class Turnstile extends TurnstileActions
{
	private State itsState;
	private static String itsVersion= "";
	
	// переменные экземпляров для каждого состояния 
	private static Locked its LockedState; 
	private static Unlocked its UnlockedState;
	
	
	
	public Turnstile()
	{
		iteLockedState = new Locked(); 
		itsUnlockedState = new Unlocked();
		
		itsState = itsLockedState;
	}
	// Entry функции для: Locked
	// функции-предки

	public String getVersion()
	{
		return itsVersion;
	}
	
	
	public String getCurrentStateName()
	{
		return itsState.stateName();
	}

	// функции событий - перед текущим State
	
	public void pass() throws FSMError
	{
		its State.pass();
	}
	
	public void coin() throws FSMError
	{
		itsState.coin();
	}

	// private class State
	// Это базовый класc Slate
	//
	private abstract class State
	{
		public abstract String stateName();
		
		// заданные по умолчанию функции событий
		
		public void pass() throws FSMError
		{
			throw new FSMError( "pass", itsState.stateName());
		}
		
		public void coin() throws FSMError
		{
			throw new FSMError( "coin", itsState.stateName());
		}
	}
		
	// class Locked
	// обрабатывает Locked State и его события
	//
	
	private class Locked extends State
	{
		public String stateName()
			{ return "Locked"; }
			
		// отвечает событию coin //
	
		public void coin()
		{
			unlock();
			// изменить состояние 
			itsstate = itsUnlockedstate;
		}
		
		//
		// отвечает событию раѕѕ
		
		public void pass()
		{
			alarm();
			itsState = itsLockedState;
		}
	}


// класс Unlocked
// обрабатывает Unlocked State и его события
//
	private class Unlocked extends State
	{
		public String stateName()
			{ return "Unlocked"; }
			
		public void pass()
		{
			lock();
			// изменяет состояние
			itsState = itsLockedState;
		}
// соответствует событию coin
//
		public void coin()
		{
			thankyou();
			// изменяет состояние
			itsState = itsUnlockedState;
		}
	}
}