#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/42840
//auto, iterator 전위, 후위 증가 확인.

auto p1 = { 1, 2, 3, 4, 5 };
auto p2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
auto p3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int n1 = 0, n2 = 0, n3 = 0;
	auto it1 = p1.begin();
	auto it2 = p2.begin();
	auto it3 = p3.begin();
	for (const auto& a : answers) {
		n1 = (*it1 == a) ? n1 + 1 : n1;
		n2 = (*it2 == a) ? n2 + 1 : n2;
		n3 = (*it3 == a) ? n3 + 1 : n3;

		if (++it1 == p1.end())
			it1 = p1.begin();
		if (++it2 == p2.end())
			it2 = p2.begin();
		if (++it3 == p3.end())
			it3 = p3.begin();
	}
	int maxRes = max(max(n1, n2), n3);
	if (maxRes == n1)
		answer.push_back(1);
	if (maxRes == n2)
		answer.push_back(2);
	if (maxRes == n3)
		answer.push_back(3);

	return answer;
}