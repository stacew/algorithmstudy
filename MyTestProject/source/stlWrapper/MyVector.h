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
		// for�� ������ Ȯ���ϴ� �� ���� 3% ���� ���� ������.
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


		//�׽�Ʈ ���̽��� �� ��������,
		//�⺻ ���Ŀ����� ���� ���̰� ������,
		//STL�� ��� ������ ��, ó���� 10% ������ ������� ����.
		//CheckSubArray()�� 1% ������ ��.
		//���� ���� ���ĵ� CheckSubArray()�� ���� .
		//�׷��� �⺻ �ڷ��� �����Ͱ� ���� TC�� �����Ժ��� �׳� ���� ���°� ���� ���δ�.
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