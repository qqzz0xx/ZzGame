#pragma once
template<class _Ty>
class Singleton
{
public:
	static _Ty* getInstance()
	{
		static _Ty inst;
		return &inst;
	}
};

