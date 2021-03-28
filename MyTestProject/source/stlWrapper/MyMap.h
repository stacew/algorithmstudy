#pragma once
#include "../allocator/MyAllocator.h"
#include <map>

template <typename _Kty, typename _Ty, typename _Pr = std::less<_Kty> >
#ifdef CUSTOM_ALLOCATOR
class MyMap : public std::map< _Kty, _Ty, _Pr, MyAllocator< std::pair < const _Kty, _Ty > > > {
	using super = std::map< _Kty, _Ty, _Pr, MyAllocator< std::pair < const _Kty, _Ty > > >;
#else
class MyMap :public std::map< _Kty, _Ty, _Pr > {
	using super = std::map< _Kty, _Ty, _Pr >;
#endif
	using sIterator = typename super::iterator;
public:



};

template <typename _Kty, typename _Ty, typename _Pr = std::less<_Kty> >
#ifdef CUSTOM_ALLOCATOR
class MyMultimap :public std::multimap < _Kty, _Ty, _Pr, MyAllocator< std::pair < const _Kty, _Ty> > > {
	using super = std::multimap < _Kty, _Ty, _Pr, MyAllocator< std::pair < const _Kty, _Ty> > >;
#else
class MyMultimap : public std::multimap < _Kty, _Ty, _Pr > {
	using super = std::multimap < _Kty, _Ty, _Pr >;
#endif
	using sIterator = typename super::iterator;
public:



};
