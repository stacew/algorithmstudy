#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/42747

int solution(vector<int> citations) {

	sort(citations.begin(), citations.end());

	for (int i = 0; i < citations.size(); i++) {
		int paperCount = citations.size() - i;
		int checkH = citations[i];
		if (checkH >= paperCount) {
			return paperCount;
		}
	}

	return 0;
}