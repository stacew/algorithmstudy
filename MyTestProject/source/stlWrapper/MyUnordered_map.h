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




//pair�� ������ ����ϴ� map ���� �� �߰��� ����ϴ� �������� �پ��� �Է��� �Ǵ� �κп� �ڵ� �������� �����ϴ°� ���ٰ� �����ż� define �߰�.
#define STD_MAKE_PAIR std::make_pair 
#if 0 //pair �ڵ� ������
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
