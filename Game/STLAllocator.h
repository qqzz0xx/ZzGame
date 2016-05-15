#pragma once
#include "pch.h"
#include "DataChunk.h"
#include "Construct.h"

struct HeapAllocator
{
	static DataChunk* Instance();
};
struct FrameAllocator
{
	static DataChunk* Instance();
};
struct GlobalAllocator
{
	static DataChunk* Instance();
};

DataChunk* FrameAllocator();
DataChunk* GlobalAllocator();

template<class _Ty, class _TAlloc = HeapAllocator>
class STLAllocator
{
public:
	typedef _Ty value_type;
	typedef value_type *pointer;
	typedef value_type &reference;
	typedef const value_type *const_pointer;
	typedef const value_type &const_reference;
	typedef size_t size_type;
	typedef int difference_type;

	template<class _Other>
	struct rebind
	{
		typedef STLAllocator<_Other, _TAlloc> other;
	};

	DataChunk* GetAllocator()
	{
		return _TAlloc::Instance();
	}

	STLAllocator()
	{

	}

	STLAllocator(const STLAllocator<_Ty, _TAlloc> &alt)
	{

	}

	template<class _Other>
	STLAllocator(const STLAllocator<_Other, _TAlloc> &alt)
	{

	}

	pointer address(reference _val)
	{
		return &_val;
	}

	const_pointer address(const_reference _val)
	{
		return &_val;
	}

	void deallocate(pointer _ptr, size_type)
	{
		if (GetAllocator())
		{
			// 不会主动释放内存;
		}
		else  // Heap Free
		{
			free(_ptr);
		}
	}

	pointer allocate(size_type _cnt)
	{
		if (GetAllocator())
		{
			return (pointer)GetAllocator()->Alloc(_cnt * sizeof(_Ty));
		}
		else
		{
			return (pointer)malloc(_cnt * sizeof(_Ty));
		}
	}

	pointer allocate(size_type _Count, const void *)
	{
		return (allocate(_Count));
	}

	void construct(pointer _Ptr, const _Ty &_Val)
	{
		Construct(_Ptr, _Val);
	}

	void destroy(pointer _Ptr)
	{
		Destroy(_Ptr);
	}


	size_type max_size()
	{
		return __max((size_t)(-1) / sizeof(_Ty), 0);
	}
};

