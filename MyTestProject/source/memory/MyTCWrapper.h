#pragma once
#include <tcmalloc.h> //todo mimalloc


class MyTCWrapper {
public:
#if 0
	// MyAllocator �������̵� �� �ʿ�
	inline void* operator new(size_t size) {
		return malloc(size);
	}
	inline void* operator new[](size_t size) {
		return malloc(size);
	}
	inline void operator delete (void* object) {
		free(object);
	}
	inline void operator delete[](void* object) {
		free(object);
	}
#endif
};