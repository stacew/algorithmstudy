#include <array>
#include <future>
#define TEST_CODE 1
#if TEST_CODE
#include <chrono>
#include <thread>
using std::this_thread::sleep_for;
//sleep_for(std::chrono::milliseconds(30));
#endif
class SpinLock {
public:
	void WaitAndLock() {
		while (m_SpinLock.test_and_set(std::memory_order_acquire));
	}
	void Unlock() {
		m_SpinLock.clear(std::memory_order_release);
	}
private:
	std::atomic_flag m_SpinLock = ATOMIC_FLAG_INIT;
};

class ASyncIterator {
#if TEST_CODE
public:
	int m_nTestCounter;
private:
	static constexpr int TEST_ITER_ARRAY_COUNT = 10000;
#endif
private:
	struct apiData {
		std::string dummy;
	};

	struct lockedData :public SpinLock {
		enum class eState : uint8_t { init, writed, exit, } m_eState;
		apiData d;
	};

	static constexpr int ASYNC_ITER_Q_SIZE = 10000;
	using arrayForCircular = std::array< lockedData, ASYNC_ITER_Q_SIZE >;

private:
	//1
	int m_nStart;
	int m_nEnd;
	//2
	int m_nProgress;
	apiData m_dummyData;

public:
	arrayForCircular dataQ;
	arrayForCircular::iterator qIter;
	arrayForCircular::iterator userIter;
	std::future< void > m_future;

	ASyncIterator() {
#if TEST_CODE
		m_nTestCounter = 0;
#endif

		m_nStart = 0;
		m_nEnd = TEST_ITER_ARRAY_COUNT - 1;

		m_nProgress = m_nStart - 1;

		//async
		for (auto& d : dataQ)
			d.m_eState = lockedData::eState::init;
		qIter = dataQ.begin();								// fixed
		userIter = prevCircular(dataQ.end());				// fixed
		userIter->WaitAndLock();
		m_future = std::async(std::launch::async, [&]() { asyncFillQ(); });
	}


	bool HasNext() {
		userIter->Unlock();
		IterCircularPlusPlus(userIter); // ++

		while (true) {
			userIter->WaitAndLock();
			lockedData::eState check = userIter->m_eState;
			userIter->Unlock();

			if (check == lockedData::eState::writed)
				break;
			else if (check == lockedData::eState::init)
				continue;
			else if (check == lockedData::eState::exit)
				return false;
		}

		userIter->WaitAndLock();
		userIter->m_eState = lockedData::eState::init;
		return true;
	}
public:
	apiData GetData() { return qIter->d; }
private:
	void asyncFillQ() {

		while (findNext()) {

			waitForRead();

			qIter->WaitAndLock();
			qIter->m_eState = lockedData::eState::writed;
			qIter->d = m_dummyData;//set founed item
			qIter->Unlock();

			IterCircularPlusPlus(qIter); //++
#if TEST_CODE
			++m_nTestCounter;
#endif  
		}

		waitForRead();
		qIter->WaitAndLock();
		qIter->m_eState = lockedData::eState::exit;
		qIter->Unlock();
	}

	void waitForRead() {

		bool bEscape = false;
		while (bEscape == false) {
			qIter->WaitAndLock();
			bEscape = (qIter->m_eState == lockedData::eState::init) ? true : false;
			qIter->Unlock();
		}
	}

	arrayForCircular::iterator prevCircular(arrayForCircular::iterator iter) {
		if (dataQ.begin() == iter)
			return dataQ.end() - 1;

		return iter - 1;
	}
	arrayForCircular::iterator nextCircular(arrayForCircular::iterator iter) {
		if (dataQ.end() - 1 == iter)
			return dataQ.begin();

		return iter + 1;
	}
	void IterCircularPlusPlus(arrayForCircular::iterator& ref_Iter) {
		ref_Iter = nextCircular(ref_Iter);
	}

	bool findNext() {
		if (m_nProgress == m_nEnd)
			return false;

		//set founed item
		m_dummyData.dummy = "dummy";

		m_nProgress += 1;
		return true;
	}
};



#include <iostream>
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	using namespace std;

	for (int i = 0; i < 10000000; i++) {

		cout << "____________________________________________" << endl;

		ASyncIterator iter;

		int count = 0;
		while (iter.HasNext()) {
			count++;
		}


#if TEST_CODE
		if (count == iter.m_nTestCounter) {
			cout << "Successs!! iter.m_nTestCounter : " << count << ", index : " << i << endl;
			continue;
		}

		cout << "Fail!!" << endl;
		cout << "count \t\t: " << count << endl;
		cout << "iter.m_nTestCounter\t: " << iter.m_nTestCounter << endl;
		break;
#endif
	}
}