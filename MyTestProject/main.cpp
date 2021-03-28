#include "source/memory/MyTCWrapper.h"

#include <iostream>
#include <chrono>
#include <future>
using namespace std;
constexpr int taskTime = 500000;
constexpr int asyncCount = 6;

class ComplexTC : public MyTCWrapper {
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
#include "source/etl/MyEtlVector.h"
int main() {
	
	MyVector<ComplexTC> test1;
	test1.push_back(ComplexTC(1,2));
	
	MyUnordered_map<int, int> umap;
	umap.insert(std::make_pair(1, 2));
	

	MyMap<int, int> map;
	map.insert(std::make_pair(1, 2));

	MyEtlVector<int> test2;
	test2.push_back(1);


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

	return 0;
}
