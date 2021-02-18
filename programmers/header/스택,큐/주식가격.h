#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/42584
//stack ( 인덱스 = 시간, pair 사용이 좋아보이지만 동일 값 )
//stack에서 pop 할 때, 차이로 얻을 수 있는 부분과 무조건 vector의 _back() 뒷 삽입이 아닌 점에 대해서도 생각이 필요.

//pq(pair, auto compare( (greater top), lambda, decltype )
vector<int> solution(vector<int> prices) {
	vector<int> answer;
	answer.resize(prices.size());

	stack<int> stkIT;//key ( =index, =time );
	for (size_t t = 0; t < prices.size(); t++) {
		while (stkIT.empty() == false && prices[stkIT.top()] > prices[t]) { //기존 것 보다 새로운 것의 가격이 작다면
			answer[stkIT.top()] = t - stkIT.top();//인덱스에 현재 시간과의 차이 계산 삽입.
			stkIT.pop();
		}
		stkIT.push(t);
	}

	size_t t = prices.size() - 1;
	while (stkIT.empty() == false) { //남아있는 값을 처리
		answer[stkIT.top()] = t - stkIT.top();
		stkIT.pop();
	}

	return answer;
}

vector<int> solution_pq(vector<int> prices) {
	vector<int> answer;
	answer.resize(prices.size());

	using pricestime = pair<int, int>;//price, time
	auto compare = [](const pricestime& l, const pricestime& r) { return l.first < r.first; }; // greater top
	priority_queue< pricestime, vector< pricestime >, decltype(compare) > pq(compare);

	for (size_t t = 0; t < prices.size(); t++) {
		int p = prices[t];
		while (pq.empty() == false && pq.top().first > p) {
			answer[pq.top().second] = t - pq.top().second;
			pq.pop();
		}

		pq.push(pricestime(p, t));
	}

	int t = prices.size() - 1;
	while (pq.empty() == false ){
		answer[pq.top().second] = t - pq.top().second;
		pq.pop();
	}

	return answer;
}