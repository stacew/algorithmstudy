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
		// for�� ������ Ȯ���ϴ� �� ���� 3% ���� ���� ������.
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


		//�׽�Ʈ ���̽��� �� ��������,
		//�⺻ ���Ŀ����� ���� ���̰� ������,
		//STL�� ��� ������ ��, ó���� 10% ������ ������� ����.
		//CheckSubArray()�� 1% ������ ��.
		//���� ���� ���ĵ� CheckSubArray()�� ���� .
		//�׷��� �⺻ �ڷ��� �����Ͱ� ���� TC�� �����Ժ��� �׳� ���� ���°� ���� ���δ�.
	}

	//�Ҿ��� ���� : O( N Log N ) : �������� ����
	void SortAll() { std::sort(super::begin(), super::end()); }
	//�Ҿ��� ���� : O( N Log N ) : �������� ����
	void SortAll_Reverse() { std::sort(super::rbegin(), super::rend()); }
	//���� ���� : O( N Log N ), space O( N )
	void Stable_Sort() { std::stable_sort(super::begin(), super::end()); }

	//O( N )
	void Reverse() { std::reverse(super::begin(), super::end()); }

	//O( log N ) : �������� ���� ���¿��� ��� ����
	bool Binary_search(const _Ty& val) { return std::binary_search(super::begin(), super::end(), val); }
	//O( log N ) : �������� ���� ���¿��� ��� ����
	bool Binary_search_Reverse(const _Ty& val) { return std::binary_search(super::rbegin(), super::rend(), val); }

	//GetBinarySearchIterator()

	//O( N ) : iterator ��ȯ
	sIterator GetMax() { return std::max_element(super::begin(), super::end()); }
	//O( N ) : iterator ��ȯ
	sIterator GetMin() { return std::min_element(super::begin(), super::end()); }
	//O( N ) : iterator ��ȯ
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

	//����
	test.SortAll();
	test2.SortAll_CheckSubArray();

	//����
	for (int i = 0; i < test.size(); i++) {
		if (test[i] != test2[i])
			return 0;
	}

	//���� ���� -> ���� �ӵ�
	test.SortAll();
	test2.SortAll_CheckSubArray();

	test.push_back(50000000);
	test2.push_back(50000000);

	//���� �� ���� �ӵ�
	test.SortAll();
	test2.SortAll_CheckSubArray();

	return 0;
}
#endif