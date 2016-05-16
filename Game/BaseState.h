#pragma once
class BaseState
{
private:
	bool mIsFinish;
public:
	BaseState();
	~BaseState();
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Exit() = 0;
	bool IsFinish()
	{
		return mIsFinish;
	}
	void Finish()
	{
		mIsFinish = true;
	}
};

