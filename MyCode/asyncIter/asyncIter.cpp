#include <iostream>
#include <array>
#include <future>
class ExampleData {
	int data;
};

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

#define TEST_CODE 1
class ASyncIterator {
private:
	class LockedData :public SpinLock {
	public:
		enum class eState : char {
			None,
			Writed,
			Exit,
		};

		eState m_eState;

		int m_nPos;
		ExampleData m_Ex;
	};

	static constexpr int ASYNC_ITER_Q_SIZE = 1000;
	static constexpr int TEST_ITER_ARRAY_COUNT = 10000;

private:
	int m_nStart;
	int m_nEnd;

	int m_nIterPos;
	ExampleData m_Ex;

#if TEST_CODE
private:
	int m_nTestCounter;
public:
	int GetTestCount() { return m_nTestCounter; }
#endif

public:
	std::array< LockedData, ASYNC_ITER_Q_SIZE > m_q;
	int qPos;
	int userPos;
	std::future< void > m_future;

	ASyncIterator() {
#if TEST_CODE
		m_nTestCounter = 0;
#endif
		m_nStart = 0;
		m_nEnd = TEST_ITER_ARRAY_COUNT - 1;


		m_nIterPos = m_nStart - 1;


		//동기화 처리
		userPos = ASYNC_ITER_Q_SIZE - 1;        // fixed : ASYNC_ITER_Q_SIZE - 1
		qPos = 0;                    // fixed : 0  
		m_future = std::async([&]() { asyncFillQ(); });  //std::launch::async,
	}


	bool HasNext() {
		m_q[userPos].Unlock();
		userPos = nextPos(userPos); // ++

		while (true) {
			m_q[userPos].WaitAndLock();
			LockedData::eState check = m_q[userPos].m_eState;
			m_q[userPos].Unlock();

			if (check == LockedData::eState::None)
				continue;
			else if (check == LockedData::eState::Writed)
				break;
			else if (check == LockedData::eState::Exit)
				return false;
		}

		m_q[userPos].WaitAndLock();
		m_q[userPos].m_eState = LockedData::eState::None;
		return true;
	}
public:
	int GetPos() { return m_q[userPos].m_nPos; }
	ExampleData GetEX() { return m_q[userPos].m_Ex; }
private:
	void asyncFillQ() {

		while (findNext()) {

			waitForReading();

			m_q[qPos].WaitAndLock();
			m_q[qPos].m_eState = LockedData::eState::Writed;
			m_q[qPos].m_nPos = m_nIterPos;
			m_q[qPos].m_Ex = m_Ex;//set founed item
			m_q[qPos].Unlock();

			qPos = nextPos(qPos); // ++

#if TEST_CODE
			++m_nTestCounter;
#endif  
		}

		waitForReading();
		m_q[qPos].WaitAndLock();
		m_q[qPos].m_eState = LockedData::eState::Exit;
		m_q[qPos].Unlock();
	}

	void waitForReading() {

		bool bEscape = false;
		while (bEscape == false) {
			m_q[qPos].WaitAndLock();
			bEscape = (m_q[qPos].m_eState == LockedData::eState::None) ? true : false;
			m_q[qPos].Unlock();
		}
	}

	static int nextPos(int a_Pos) {
		a_Pos += 1;
		return a_Pos == ASYNC_ITER_Q_SIZE ? 0 : a_Pos;
	}

	bool findNext() {
		if (m_nIterPos == m_nEnd)
			return false;

		//set founed item
		//m_Ex = ; 
		m_nIterPos += 1;
		return true;
	}
};


static auto ____ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return true;
}();

int main() {
	using namespace std;

	for (int i = 0; i < 10000000; i++) {

		cout << "____________________________________________" << endl;

		ASyncIterator iter;

		int count = 0;
		while (iter.HasNext()) {
			count++;
		}


#if TEST_CODE
		if (count == iter.GetTestCount()) {
			cout << "Successs!! GetTestCount() : " << count << ", index : " << i << endl;
			continue;
		}

		cout << "Fail!!" << endl;
		cout << "count \t\t: " << count << endl;
		cout << "GetTestCount()\t: " << iter.GetTestCount() << endl;
		break;
#endif
	}
}