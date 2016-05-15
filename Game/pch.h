#pragma once

#define STL_TEMPLATE_MEMBER(_Ty) \
	typedef _Ty value_type;\
	typedef value_type *pointer;\
	typedef value_type &reference;\
	typedef const value_type *const_pointer;\
	typedef const value_type &const_reference;\
	typedef size_t size_type;\
	typedef int difference_type;


template<class _Ty>
bool TYPE_TRAITS_IS_BUILT_IN_TYPE(_Ty ty)
{
	return false;
}


