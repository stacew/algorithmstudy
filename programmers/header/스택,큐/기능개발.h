#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42586
q pair 넣는 방법 외에 미리 필요한 day를 계산해서 넣는 방식
#endif


vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int taskCount = progresses.size();
	queue<pair<int, int>> q;
	for (int i = 0; i < taskCount; i++) {
		q.push(pair<int, int>(progresses[i], speeds[i]));
	}

	int day = 0;
	while (q.empty() == false) {
		auto ps = q.front();
		while (ps.first + ps.second * day < 100) {
			day++;
		}

		answer.push_back(0);

		do {
			answer[answer.size() - 1]++;

			q.pop();
			if (q.empty())
				break;

			ps = q.front();
		} while (ps.first + ps.second * day >= 100);
	}

	return answer;
}