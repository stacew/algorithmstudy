#pragma once
#if 0
https://www.hackerrank.com/challenges/flipping-bits/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
��Ŀ��ũ�� long 8 byte, MSVC long 4 byte�� ����� �ٸ�.
long long ó���� unsigned�� ���̸� � ��ȭ�� �ִ��� Ȯ���� ����..
#endif


long long flippingBits(long long n) {
	long long ret = n;//check1
	ret = ~n; //check2
    ret = (unsigned)ret; //answer
	return ret;
}


#if 0 //��Ŀ��ũ
long flippingBits(long n) {
	return (unsigned)~n;
}
#endif

#if 0
#include "header/Miscellaneous/Flipping bits.h"
int main() {
	cout << flippingBits(100000);
	return 0;
}
#endif