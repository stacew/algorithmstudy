#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42587
pq, q, pair
#endif

#define LOCATION second
int solution(vector<int> priorities, int location) {
	priority_queue<int> pq;
	queue<pair<int, int>> q;

	for (size_t i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
		q.push(pair<int, int>(priorities[i], i));
	}

	int printCount = 0;
	while (true) {
		while (q.front().first != pq.top()) {
			auto front = q.front();
			q.pop();
			q.push(front);
		}
		pq.pop();

		printCount++;
		if (q.front().LOCATION == location)
			break;

		q.pop();		
	}

	return printCount;
}