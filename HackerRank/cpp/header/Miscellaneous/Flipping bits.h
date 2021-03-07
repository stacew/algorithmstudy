#pragma once
#if 0
https://www.hackerrank.com/challenges/flipping-bits/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
해커랭크는 long 8 byte, MSVC long 4 byte로 결과가 다름.
long long 처리로 unsigned를 붙이면 어떤 변화가 있는지 확인은 가능..
#endif


long long flippingBits(long long n) {
	long long ret = n;//check1
	ret = ~n; //check2
    ret = (unsigned)ret; //answer
	return ret;
}


#if 0 //해커랭크
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