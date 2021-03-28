#include "source/memory/MyTCWrapper.h"

#include <iostream>
#include <chrono>
#include <future>
using namespace std;
constexpr int taskTime = 500000;
constexpr int asyncCount = 6;

class ComplexTC : public MyTCWrapper {
//	bool dummy[100000000]{};
public:
	ComplexTC(double a, double b) : r(a), c(b) {
	}
	ComplexTC() : r(0), c(0) {
	}
	~ComplexTC() {

	}
private:
	double r;
	double c;
};
auto TestTC(int _count) {
	auto start = std::chrono::system_clock::now();
	if (_count == 0)
		return start - start; //0

	auto futureTC = std::async(std::launch::async, TestTC, _count - 1);
	for (int i = 0; i < taskTime; i++) {
		ComplexTC* pTest = new ComplexTC(3, 4);
		delete pTest;
		ComplexTC* pTest2 = new ComplexTC[100];
		delete[] pTest2;
	}
	futureTC.get();
	return std::chrono::system_clock::now() - start;
}

class Complex {
//	bool dummy[100000000]{};
public:
	Complex(double a, double b) : r(a), c(b) {
	}
	Complex() : r(0), c(0) {
	}
	~Complex() {

	}
private:
	double r;
	double c;
};
auto Test(int _count) {
	auto start = std::chrono::system_clock::now();
	if (_count == 0)
		return start - start; //0

	auto futureTC = std::async(std::launch::async, Test, _count - 1);
	for (int i = 0; i < taskTime; i++) {
		Complex* pTest = new Complex(3, 4);
		delete pTest;
		Complex* pTest2 = new Complex[100];
		delete[] pTest2;
	}
	futureTC.get();
	return std::chrono::system_clock::now() - start;
}


#include "source/stlWrapper/MyVector.h"
#include "source/stlWrapper/MyUnordered_map.h"
#include "source/stlWrapper/MyMap.h"
#include "source/etl/EtlVector.h"
int main() {
#if 1
	MyVector<Complex> vecComplex;
	cout << "- - - " << endl;
	vecComplex.push_back(*(new Complex(1,2)));
	cout << "- - - " << endl;

	MyVector<ComplexTC> vecComplexTC;
	cout << "- - - " << endl;
	vecComplexTC.push_back(*(new ComplexTC(1, 2)));
	cout << "- - - " << endl;
#endif
#if 1
	MyUnordered_map<int, int> umap;
	cout << "- - - " << endl;
	umap.insert(std::make_pair(1, 2));
	cout << "- - - " << endl;
	
	MyMap<int, int> map;
	cout << "- - - " << endl;
	map.insert(std::make_pair(1, 2));
	cout << "- - - " << endl;
#endif

#if 1
	EtlVector<Complex> test3;
	cout << "- - - " << endl;
	test3.push_back(Complex(1, 2));
	cout << "- - - " << endl;

	EtlVector<ComplexTC> test4;
	for(int i = 0; i < 100; i++)
		test4.push_back(ComplexTC(1,2));
	cout << "- - - " << endl;
#endif
#if 0
	auto futureTC = std::async(std::launch::async, []() {return TestTC(asyncCount); });
	cout << "TC\t" << futureTC.get().count() / 100000;
	for (int i = 0; i < 5; i++) {
		auto futureTC = std::async(std::launch::async, []() {return TestTC(asyncCount); });
		cout << ", " << futureTC.get().count() / 100000;
	}

	auto future = std::async(std::launch::async, []() { return Test(asyncCount); });
	cout << "normal\t" << future.get().count() / 100000;
	for (int i = 0; i < 5; i++) {
		future = std::async(std::launch::async, []() { return Test(asyncCount); });
		cout << ", " << future.get().count() / 100000;
	}
#endif
	return 0;
}
