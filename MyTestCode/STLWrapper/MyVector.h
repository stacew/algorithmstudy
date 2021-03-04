#pragma once
#include "MyAllocator.h"
#include <vector>


#include <algorithm>
//std::sort, std::stable_sort -> std::binary_search
//std::find
//std::max_element, std::min_element

#include <numeric>
//std::accumulate, std::Multiplies


template< typename _Ty>
#ifdef CUSTOM_ALLOCATOR
class MyVector : public BrBase, public std::vector< _Ty, MyAllocator<_Ty> > {
#else
class MyVector : public BrBase, public std::vector< _Ty > {
#endif
	using super = std::vector< _Ty, MyAllocator<_Ty> >;
	using sIterator = typename super::iterator;
public:

	//불안정 정렬 : O( N Log N ) : 오름차순 정렬
	void SortAll() { std::sort(super::begin(), super::end()); }
	//불안정 정렬 : O( N Log N ) : 내림차순 정렬
	void SortAll_Reverse() { std::sort(super::rbegin(), super::rend()); }
	//안정 정렬 : O( N Log N ), space O( N )
	void Stable_Sort() { std::stable_sort(super::begin(), super::end()); }

	//O( N )
	void Reverse() { std::reverse(super::begin(), super::end()); }

	//O( log N ) : 오름차순 정렬 상태에서 사용 가능
	bool Binary_search(const _Ty& val) { return std::binary_search(super::begin(), super::end(), val); }
	//O( log N ) : 내림차순 정렬 상태에서 사용 가능
	bool Binary_search_Reverse(const _Ty& val) { return std::binary_search(super::rbegin(), super::rend(), val); }

	//GetBinarySearchIterator()

	//O( N ) : iterator 반환
	sIterator GetMax() { return std::max_element(super::begin(), super::end()); }
	//O( N ) : iterator 반환
	sIterator GetMin() { return std::min_element(super::begin(), super::end()); }
	//O( N ) : iterator 반환
	sIterator Find(const _Ty& val) { std::find(super::begin(), super::end(), val); }

};