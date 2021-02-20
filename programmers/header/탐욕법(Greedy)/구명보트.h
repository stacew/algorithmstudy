#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42885
iterator 비교, 인덱스가 더 보기 쉬움.

#endif

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end(), greater<int>());
	auto l = people.begin();    auto r = people.end() - 1;

	int temp = 0;
	while (l <= r) {
		if (temp >= *l)
			temp -= *l++;
		else if (temp >= *r)
			temp -= *r--;
		else {
			temp = limit;
			answer++;
		}
	}

	return answer;
}