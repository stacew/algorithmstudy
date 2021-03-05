#pragma once
//#include "MyAllocator.h"
#include <vector>

#include <algorithm>
//std::sort, std::stable_sort -> std::binary_search
//std::find
//std::max_element, std::min_element

#include <numeric>
//std::accumulate, std::Multiplies


template< typename _Ty>
#ifdef CUSTOM_ALLOCATOR
class MyVector : public std::vector< _Ty, MyAllocator<_Ty> > {
	using super = std::vector< _Ty, MyAllocator<_Ty> >;
#else
class MyVector : public std::vector< _Ty > {
	using super = std::vector< _Ty >;
#endif	
	using sIterator = typename super::iterator;
public:


	void SortAll_CheckSubArray() {
		// for문 내에서 확인하는 것 보다 3% 정도 성능 좋아짐.
		sIterator sbegin = super::begin();
		sIterator send = super::end();

		sIterator right = send;
		_Ty max = *sbegin;
		for (auto it = sbegin; it != send; it++) {
			if (*it < max)
				right = it;
			max = std::max(max, *it);
		}
		if (right == send)
			return;

		sIterator left = send - 1;
		_Ty min = *left;
		do {
			if (min < *left)
				left = left;
			min = std::min(min, *left);
		} while (--left != sbegin);

		std::sort(left, ++right);


		//테스트 케이스는 한 번이지만,
		//기본 정렬에서는 거의 차이가 없었고,
		//STL의 경우 재정렬 시, 처음의 10% 정도의 비용으로 끝남.
		//CheckSubArray()는 1% 정도로 끝.
		//편집 이후 정렬도 CheckSubArray()가 빠름 .
		//그런데 기본 자료형 데이터가 많은 TC라 복잡함보단 그냥 순정 쓰는게 좋아 보인다.
	}

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


#if 0
int main() {
	MyVector<int> test;
	MyVector<int> test2;
	for (int i = 0; i < 50000000; i++) {
		int data = rand();
		test.push_back(data);
		test2.push_back(data);
	}

	//정렬
	test.SortAll();
	test2.SortAll_CheckSubArray();

	//검증
	for (int i = 0; i < test.size(); i++) {
		if (test[i] != test2[i])
			return 0;
	}

	//정렬 상태 -> 정렬 속도
	test.SortAll();
	test2.SortAll_CheckSubArray();

	test.push_back(50000000);
	test2.push_back(50000000);

	//편집 후 정렬 속도
	test.SortAll();
	test2.SortAll_CheckSubArray();

	return 0;
}
#endif