#pragma once
#include <tcmalloc.h> //todo mimalloc

class MyTCWrapper {
public:
	void* operator new (size_t size, void* ptr) noexcept {
		return ptr;
	}
	void operator delete (void* object, void* ptr) noexcept {}

	void* operator new(size_t size) {
		return malloc(size);
	}
	void* operator new[](size_t size) {
		return malloc(size);
	}
	void operator delete (void* object) {
		free(object);
	}
	void operator delete[](void* object) {
		free(object);
	}
};