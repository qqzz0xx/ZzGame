#pragma once
#include "pch.h"
#include "Construct.h"

template<class _Ty, size_t _AllocConut>
class FixedVector
{
public:
	typedef _Ty value_type;
	typedef value_type *pointer;
	typedef value_type &reference;
	typedef const value_type *const_pointer;
	typedef const value_type &const_reference;
	typedef size_t size_type;
	typedef int difference_type;

	typedef value_type *iterator;
	typedef const value_type *const_iterator;

	typedef FixedVector<_Ty, _AllocConut> _Myt;

private:
	enum
	{
		kBuffSize = sizeof(_Ty) * _AllocConut
	};
	char mDataBuff[kBuffSize];
	_Ty *mDataPointer;
	size_t mCount;

	void resizeAlloc(size_t n)
	{
		//¹Ì¶¨³¤¶È
		assert(n <= _AllocConut);
	}

	void splitAlloc(iterator index, size_t n)
	{
		resizeAlloc(n + mCount);
		iterator it_idx = mDataPointer + index;
		memmove(it_idx + n, it_idx, n);
	}

public:
	~FixedVector() { }

	FixedVector() : mCount(0), mDataPointer((_Ty*)mDataBuff) {}

	FixedVector(const _Myt& right)
	{
		mDataPointer = (_Ty*)mDataBuff;
		mCount = right.size();
		if (mCount > 0)
		{
			for (size_t i = 0; i < mCount; i++)
			{
				Construct(&mDataPointer[i], right.mDataPointer[i]);
			}
		}
	}

	FixedVector(size_t conut, const _Ty& val)
	{
		mDataPointer = (_Ty*)mDataBuff;
		mCount = conut;
		if (mCount > 0)
		{
			for (size_t i = 0; i < mCount; i++)
			{
				Construct(&mDataPointer[i], val);
			}
		}
	}

	FixedVector(iterator begin, iterator end)
	{
		mDataPointer = (_Ty*)mDataBuff;
		mCount = end - begin;
		if (mCount > 0)
		{
			for (size_t i = 0; i < mCount; i++)
			{
				Construct(&mDataPointer[i], begin[i]);
			}
		}
	}

	size_t capacity() const { return _AllocConut; }

	iterator begin() const { return mDataPointer; }

	iterator end() const { return mDataPointer + mCount; }

	size_type size() const { return mCount; }

	bool empty() const { return mCount == 0; }

	_Ty& front() { return *mDataPointer; }

	const _Ty& front() const { return *mDataPointer; }

	_Ty& back() { return mDataPointer[mCount - 1]; }

	const _Ty& back() { return mDataPointer[mCount - 1]; }

	void push_back(const _Ty& val)
	{
		Construct(&mDataPointer[mCount], val);
		++mCount;
	}

	_Ty pop_back()
	{
		_Ty ret = mDataPointer[--mCount];
		Destroy(mDataPointer[mCount]);
		return ret;
	}

	iterator erase(iterator it)
	{
		Destroy(it);
		memcpy(it, it + 1, (uint8*)end() - (uint8*)(it + 1));
		mCount--;
		return it;
	}

	iterator erase(iterator it_begin, iterator it_end)
	{
		for (iterator it = it_begin; it != it_end; it++)
		{
			Destroy(it);
		}
		memcpy(it_begin, it_end, (uint8*)end() - (uint8*)(it_end));
		mCount -= (it_end - it_begin);
		return it_begin;
	}

	iterator insert(iterator it, const _Ty& val)
	{
		splitAlloc(it, 1);
		Construct(it, val);
		mCount++;
		return it;
	}

	void insert(iterator it, size_t n, const _Ty& val)
	{
		splitAlloc(it, n);
		for (size_t i = 0; i < n; i++)
		{
			Construct(it + i, val);
		}
		mCount += n;
	}

	void insert(iterator it, const_iterator it_begin, const_iterator it_end)
	{
		size_t n = it_end - it_begin;
		splitAlloc(it, n);
		for (size_t i = 0; i < n; i++)
		{
			Construct(it + i, *(it_begin + i));
		}
		mCount += n;
	}

	void resize(size_t size)
	{
		if (size < mCount)
		{
			resizeAlloc(size);
			for (size_t i = size; i < mCount; i++)
			{
				Destroy(mDataPointer + i);
			}			
		}
		else
		{
			resizeAlloc(size);
			for (size_t i = mCount; i < size; i++)
			{
				Construct(mDataPointer + i);
			}
		}
		mCount = size;
	}

	void resize(size_t size, const _Ty& val)
	{
		if (size < mCount)
		{
			resizeAlloc(size);
			for (size_t i = size; i < mCount; i++)
			{
				Destroy(mDataPointer + i, val);
			}
		}
		else
		{
			resizeAlloc(size);
			for (size_t i = mCount; i < size; i++)
			{
				Construct(mDataPointer + i, val);
			}
		}
		mCount = size;
	}

	_Ty& operator [] (size_t i)
	{
		return mDataPointer[i];
	}

	const _Ty& operator [] (size_t i) const
	{
		return mDataPointer[i];
	}

	_Ty& at(size_t i)
	{
		return mDataPointer[i];
	}

	const _Ty& at(size_t i) const
	{
		return mDataPointer[i];
	}

};

