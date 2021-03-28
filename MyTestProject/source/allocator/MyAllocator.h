#pragma once
#include "../memory/MyTCWrapper.h"
#if 1
#include <iostream>
using namespace std;
#endif

#define CUSTOM_ALLOCATOR

template <typename _Ty>
class MyAllocator : public MyTCWrapper {
public:
	using value_type = _Ty;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	using const_void_pointer = const void*;
	using size_type = size_t;

	MyAllocator() {
		cout << "MyAllocator()" << endl;
	};
	~MyAllocator() {
		cout << "~MyAllocator()" << endl;
	};
#if 0
	template <class U> struct rebind { typedef allocator<U> other; };
#endif
	template <typename U>
	MyAllocator(const MyAllocator<U>& other) {
		cout << "MyAllocator<U>()" << endl;
	}

	pointer allocate(size_type objCount) {
		cout << "+ allocate()" << endl;
		return static_cast<pointer>(operator new(sizeof(value_type) * objCount));
		
	}
	void deallocate(pointer p, size_type objCount) {
		cout << "- deallocate()" << endl;
		operator delete(p);
	}

	template<typename U, typename... _Valty>
	void construct(U* p, _Valty&&... _Val) {
		cout << "construct()" << endl;
		auto tester = new(p) U(std::forward<_Valty>(_Val)...);
	}
	template <typename U>
	void destroy(U* p) {
		cout << "destroy()" << endl;
		p->~U();
	}
};