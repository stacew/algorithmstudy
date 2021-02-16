#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/42584
//pq(pair, auto compare(greater top) lambda decltype)
//todo stack.
vector<int> solution(vector<int> prices) {
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