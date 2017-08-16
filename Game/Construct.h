#pragma once
#include "pch.h"
#include <new.h>
#include "DataChunk.h"

template<class _Ty, class _TAlloc = FrameAllocator>
inline _Ty* New()
{
	void* ptr = _TAlloc::Instance()->Alloc(sizeof(_Ty));
	return new ((void*)ptr) _Ty();
}

template<class _Ty>
inline void Construct(_Ty *ptr)
{
	new ((void*)ptr) _Ty();
}
template<class _Ty, class T1>
inline void Construct(_Ty *ptr, T1 val1)
{
	new ((void*)ptr) _Ty(val1);
}
template<class _Ty, class T1, class T2>
inline void Construct(_Ty *ptr, T1 val1, T2 val2)
{
	new ((void*)ptr) _Ty(val1, val2);
}
template<class _Ty, class T1, class T2, class T3>
inline void Construct(_Ty *ptr, T1 val1, T2 val2, T3 val3)
{
	new ((void*)ptr) _Ty(val1, val2, val3);
}

template<class _Ty>
inline void Destroy(_Ty *ptr)
{
	//if (!TYPE_TRAITS_IS_BUILT_IN_TYPE(*ptr))
	{
		ptr->~_Ty();
	}
}
template<class _Ty>
inline void Destroy(_Ty *ptr, size_t count)
{
	for (size_t i = 0; i < length; i++)
	{
		ptr->~_Ty();
		++ptr;
	}
}