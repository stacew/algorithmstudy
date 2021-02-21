#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42628
multiset 최소, 최대 구하기가 더 쉬웠음.
성능 테스트 결과(다양한 데이터 테스트 X)
solution : solution_pqpquMap = 5(3052ms~15062ms) : 4(2404ms~11812ms)
pqpqMap이 약간 빠름
메모리는 pqpqMap이 좀 더 많음.Delete 없이 Insert만 해도 비례로 차이날 듯.
결론 : 코드 복잡해지면 multiset 사용 고려!
#endif

vector<int> solution(const vector<string>&operations) {
	multiset<int> ms;
	for (const auto& op : operations) {
		int num = stoi(op.substr(2));

		if (*op.begin() == 'I') {//Insert
			ms.insert(num);
		}
		else {//Delete
			if (ms.size())
				ms.erase(num > 0 ? --ms.end() : ms.begin());
		}
	}
	if (ms.size())
		return { *(--ms.end()), *ms.begin() };
	return { 0,0 };
}
vector<int> solution_pqpquMap(vector<string>& operations) {
	priority_queue<int, vector<int>, greater<int>> pqMin;
	priority_queue<int> pqMax;
	unordered_map<int, int> counter;

	for (const auto& op : operations) {
		int num = stoi(op.substr(2));

		//Insert
		if (*op.begin() == 'I') {
			pqMin.push(num);
			pqMax.push(num);
			counter[num]++;
			continue;
		}

		//Delete
		if (num > 0 && pqMax.empty() == false) { //max
			counter[pqMax.top()]--;
			pqMax.pop();
		}
		else if (num < 0 && pqMin.empty() == false) { //min
			counter[pqMin.top()]--;
			pqMin.pop();
		}

		//Refresh
		while (pqMax.empty() == false && counter[pqMax.top()] == 0) {
			pqMax.pop();
		}
		while (pqMin.empty() == false && counter[pqMin.top()] == 0) {
			pqMin.pop();
		}
	}

	if (pqMax.empty() == false)
		return { pqMax.top(), pqMin.top() };
	return { 0,0 };
}