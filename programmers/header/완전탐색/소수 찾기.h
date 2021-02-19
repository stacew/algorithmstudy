#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/42839
//next_permutation, queue(bfs), uset, checkPrime
//fail: queue(bfs), stack(dfs)

int solution(string numbers) {
	int answer = 0;

	vector<int> n;
	for (int i = 0; i < numbers.size(); i++) {
		n.push_back(numbers[i] - '0');
	}
	sort(n.begin(), n.end());
	
	queue<vector<int>> q;
	int nPos = 0;
	q.push({ n[nPos++] }); // new num
	while (nPos < n.size()) {
		int nextNumber = n[nPos++];

		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			vector<int> front = q.front();
			q.pop();
			q.push(front);//1

			front.push_back(nextNumber);
			q.push(front);//2

		}
		q.push({ nextNumber });//3
	}
	//

	auto DoNumber = [](vector<int>& nums) {
		int sum = 0;
		for (const auto& n : nums) {
			sum *= 10;
			sum += n;
		}
		return sum;
	};

	//
	unordered_set<int> uSet;
	while (q.empty() == false) {
		vector<int> temp = q.front();
		q.pop();

		do {
			uSet.insert(DoNumber(temp));
		} while (next_permutation(temp.begin(), temp.end()));
	}

	//checkPrimeCount
	auto checkPrime = [](int num) {
		if (num <= 1)
			return false;

		for (int i = 2; i < num; i++) {
			if (num % i == 0)
				return false;
		}
		return true;
	};

	for (const auto& n : uSet) {
		if (checkPrime(n))
			answer++;
	}
	return answer;
}


#if 0 //¼ø¿­ÀÌ ¾Æ´Ô..
constexpr int MAX = 10000000;
int solution(string numbers) {
	int answer = 0;
	auto pMemo = make_unique<bitset<MAX>>();
	//checkPrimeCount
	auto checkPrimeCount = [&](int num) {
		if (num <= 1)
			return;
		if (pMemo->test(num))
			return;

		for (int i = 2; i < num; i++) {
			if (num % i == 0)
				return;
		}
		pMemo->set(num);
		answer++;
	};

	auto checkDigits = [](int num) {
		if (num == 0)
			return 1;

		int count = 0;
		while (num != 0) {
			num /= 10;
			count++;
		}
		return count;
	};

	//bfs
	queue<vector<int>> q;
	int strPos = 0;
	q.push({ numbers[strPos++] - '0' });
	while (strPos < numbers.size()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			vector<int> front = q.front();
			q.pop();
			q.push(front);//1

			front.push_back(numbers[strPos] - '0');
			q.push(front);//2

			q.push({ numbers[strPos] - '0' });//3
		}
		strPos++;
	}

	unordered_set<int> uSet;

	while (q.empty() == false) {
		vector<int> data = q.front();
		q.pop();

		//dfs
		stack<int> st;
		int dataPos = 0;
		st.push(data[dataPos++]);
		while (dataPos < data.size()) {
			vector<int> popVec;
			while (st.empty() == false) {
				popVec.push_back(st.top());
				st.pop();
			}

			for (int i = 0; i < popVec.size(); i++) {
				st.push(popVec[i]); //1
				st.push(popVec[i] * 10 + data[dataPos]); //2

				int digits = checkDigits(popVec[i]);
				st.push(data[dataPos] * pow(10, digits) + popVec[i]); //3
			}
			dataPos++;
		}

		while (st.empty() == false) {
			uSet.insert(st.top());
			st.pop();
		}
	}

	for (const auto& n : uSet) {
		checkPrimeCount(n);
	}
	return answer;
}
#endif