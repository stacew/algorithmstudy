#pragma once
#include "../allocator/MyAllocator.h"

#include <vector>
#include <array>
template< typename _Ty, const size_t USE_STACK_LIMIT = 64 > // Size too large causes Stack overflow.
															// default parameter is cache line 64 byte( ex : char )
#ifdef CUSTOM_ALLOCATOR
class EtlVector : protected std::vector< _Ty, MyAllocator<_Ty> > { // protected std::
	using superVec = std::vector < _Ty, MyAllocator<_Ty> >;
#else
class EtlVector : protected std::vector< _Ty > { // protected std::
	using superVec = std::vector < _Ty >;
#endif

	std::array<_Ty, USE_STACK_LIMIT> arr;
	int m_Length;
public:
	//arr init _Ty..
	EtlVector() : superVec(0) {
		m_Length = 0;
	}


	void push_back(const _Ty& _Val) {
		if (m_Length < USE_STACK_LIMIT) {
			arr[m_Length] = _Val;
		}
		else {
			superVec::emplace_back(_Val);
		}
		m_Length++;
	}
	constexpr _Ty& at(const size_t a_index) {
		if (a_index < USE_STACK_LIMIT) {
			return arr[a_index];
		}
		else {
			return superVec::at(a_index - USE_STACK_LIMIT);
		}
	}
	_Ty& operator[](const size_t a_index) {
		if (a_index < USE_STACK_LIMIT) {
			return arr[a_index];
		}
		else {
			return superVec::at(a_index - USE_STACK_LIMIT);
		}
	}
	constexpr size_t size() {
		return m_Length;
	}
};