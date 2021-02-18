#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/43165
//Queue BFS

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    queue<int> q;
    q.push(0);

	auto iter = numbers.begin();
	while (iter != numbers.end()) {

		int nPrevSize = q.size();
		for (int i = 0; i < nPrevSize; i++) {
			auto val = q.front();
			q.push(val + *iter);
			q.push(val - *iter);
			q.pop();
		}

		iter++;
	}

	while (q.empty() == false) {
		if (q.front() == target)
			answer++;
		q.pop();
	}

	return answer;
}