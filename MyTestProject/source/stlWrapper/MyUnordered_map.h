#pragma once
#include "../allocator/MyAllocator.h"
#include <unordered_map>

template <typename _Kty, typename _Ty, typename _Hasher = std::hash<_Kty>, typename _Keyeq = std::equal_to<_Kty> >
#ifdef CUSTOM_ALLOCATOR
class MyUnordered_map : public std::unordered_map< _Kty, _Ty, _Hasher, _Keyeq, MyAllocator< std::pair < const _Kty, _Ty > > > {
	using super = std::unordered_map< _Kty, _Ty, _Hasher, _Keyeq, MyAllocator< std::pair < const _Kty, _Ty > > >;
#else
class MyUnordered_map : public std::unordered_map < _Kty, _Ty, _Hasher, _Keyeq > {
	using super = std::unordered_map < _Kty, _Ty, _Hasher, _Keyeq >;
#endif
	using sIterator = typename super::iterator;
public:



};


template <typename _Kty, typename _Ty, typename _Hasher = std::hash<_Kty>, typename _Keyeq = std::equal_to<_Kty> >
#ifdef CUSTOM_ALLOCATOR
class MyUnordered_multimap : public std::unordered_multimap< _Kty, _Ty, _Hasher, _Keyeq, MyAllocator< std::pair < const _Kty, _Ty > > > {
	using super = std::unordered_multimap< _Kty, _Ty, _Hasher, _Keyeq, MyAllocator< std::pair < const _Kty, _Ty > > >;
#else
class MyUnordered_multimap : public std::unordered_multimap< _Kty, _Ty, _Hasher, _Keyeq > {
	using super = std::unordered_multimap< _Kty, _Ty, _Hasher, _Keyeq >;
#endif
	using sIterator = typename super::iterator;
public:


};




//pair를 무조건 사용하는 map 종류 및 추가로 사용하는 구조에서 다양한 입력이 되는 부분에 코딩 컨벤션을 통일하는게 좋다고 생각돼서 define 추가.
#define STD_MAKE_PAIR std::make_pair 
#if 0 //pair 코딩 컨벤션
{
	MyUnordered_map<int, int> umap;
	//umap.insert({ 1,2 });						X
	//umap.insert(std::make_pair(1, 2));		X
	//umap.insert(std::pair<int, int>(1, 2));	X
	umap.insert(STD_MAKE_PAIR(1, 2));

	MyStack< std::pair<int, int> > stk;
	//stk.push({ 1,2 });						X
	//stk.push(std::make_pair(1, 2));			X
	//stk.push(std::pair<int, int>(1, 2));		X
	stk.push(STD_MAKE_PAIR(1, 2));
}
#endif
