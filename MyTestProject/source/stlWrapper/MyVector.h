#pragma once
#include "../allocator/MyAllocator.h"
#include <vector>

#include <algorithm>
#include <numeric>


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
		_Ty maxV = *sbegin;
		for (auto it = sbegin; it != send; it++) {
			if (*it < maxV)
				right = it;
			maxV = max(maxV, *it);
		}
		if (right == send)
			return;

		sIterator left = send - 1;
		_Ty minV = *left;
		do {
			if (minV < *left)
				left = left;
			minV = min(minV, *left);
		} while (--left != sbegin);

		std::sort(left, ++right);


		//테스트 케이스는 한 번이지만,
		//기본 정렬에서는 거의 차이가 없었고,
		//STL의 경우 재정렬 시, 처음의 10% 정도의 비용으로 끝남.
		//CheckSubArray()는 1% 정도로 끝.
		//편집 이후 정렬도 CheckSubArray()가 빠름 .
		//그런데 기본 자료형 데이터가 많은 TC라 복잡함보단 그냥 순정 쓰는게 좋아 보인다.
	}

	void SortAll() { std::sort(super::begin(), super::end()); }


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