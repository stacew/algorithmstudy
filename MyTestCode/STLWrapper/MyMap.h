#pragma once
//#include "MyAllocator.h"
#include <map>

//주의 사항. key로 value를 찾는 경우, [key] == value 비교 사용 금지
//[ ]를 쓰는 순간 내부 엔트리가 생성되어 새로운 원소가 추가 됩니다.
//[key, 0]의 엔트리가 생성되기 때문에 메모리 낭비 및 다른 이터레이터 동작 시 버그 발생 가능성
//=> map.find(key) != map.end() 비교하세요 => IsExist(iter) 추가

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

	//O(log N)
	//bool IsExist(_Kty key) { return super::find(key) != super::end() ? true : false; }

	//O(log N)
	//find(_Kty key){}

	//O(1) : find 이후 반환값 iterator를 사용 가능
	bool IsExist(const sIterator& iter) { return iter != super::end() ? true : false; }
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

	//O(log N)
	//bool IsExist(_Kty key) { return super::find(key) != super::end() ? true : false; }

	//O(log N)
	//find(_Kty key){}

	//O(1) : find 이후 반환값 iterator를 사용 가능
	bool IsExist(const sIterator& iter) { return iter != super::end() ? true : false; }
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