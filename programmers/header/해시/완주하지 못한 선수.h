#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/42576
//hash counting. forRange hash, ( other. sort 후 앞, 뒤 비교 )

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> umPartic;
	for (const auto& partic : participant) {
		umPartic[partic]++;
	}

	for (const auto& comple : completion) {
		umPartic[comple]--;
	}

	for (const auto& notComple : umPartic) {
		if (notComple.second > 0) {
			answer = notComple.first;
			break;
		}
	}

	return answer;
}