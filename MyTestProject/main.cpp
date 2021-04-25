#include "source/memory/MyTCWrapper.h"
#include "source/occa/occaBuf.h"
#include <iostream>
#include <chrono>
#include <future>
using namespace std;
constexpr int taskTime = 500000;
constexpr int asyncCount = 6;

int main() {

	int testCount = 300;
	occaBuf256<char> oBuf(testCount, 1, eOcca::malloc_initZero);
	if (oBuf.isAllocFail())
		return 0;
	auto buf = oBuf.GetBuffer();
	for (int i = 0; i < 300; i++) {
		buf[i] = 'a';
	}
	
	return 0;
}
