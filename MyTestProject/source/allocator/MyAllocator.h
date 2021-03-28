#pragma once
#include "../memory/MyTCWrapper.h"

#define CUSTOM_ALLOCATOR

template <typename _Ty>
class MyAllocator : public MyTCWrapper {
public:
	using value_type = _Ty;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	using const_void_pointer = const void*;
	using size_type = size_t;

	MyAllocator() {};
	~MyAllocator() {};
	
	template <typename U>
	struct rebind { using other = MyAllocator<U>; };	
	template <typename U>
	MyAllocator(const MyAllocator<U>& other) {}

	pointer allocate(size_type ObjectNum) {
		return static_cast<pointer>(operator new(sizeof(_Ty) * ObjectNum));
	}
	void deallocate(pointer p, size_type ObjectNum) {
		operator delete(p);
	}

	template<typename U, typename... Args>
	void construct(U* p, Args&& ...args) {
		new(p) U(std::forward<Args>(args)...);
	}
	template <typename U>
	void destroy(U* p) {
		p->~U();
	}
};