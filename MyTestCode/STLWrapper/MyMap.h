#pragma once
//#include "MyAllocator.h"
#include <map>

//���� ����. key�� value�� ã�� ���, [key] == value �� ��� ����
//[ ]�� ���� ���� ���� ��Ʈ���� �����Ǿ� ���ο� ���Ұ� �߰� �˴ϴ�.
//[key, 0]�� ��Ʈ���� �����Ǳ� ������ �޸� ���� �� �ٸ� ���ͷ����� ���� �� ���� �߻� ���ɼ�
//=> map.find(key) != map.end() ���ϼ��� => IsExist(iter) �߰�

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

	//O(1) : find ���� ��ȯ�� iterator�� ��� ����
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

	//O(1) : find ���� ��ȯ�� iterator�� ��� ����
	bool IsExist(const sIterator& iter) { return iter != super::end() ? true : false; }
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