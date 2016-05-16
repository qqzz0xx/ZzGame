#pragma once
#include "BaseState.h"
class StateMachine
{
private:
	BaseState *mCurState;
public:
	StateMachine();
	~StateMachine();
	void SwitchState(BaseState* state)
	{
		mCurState = state;
	}

};

