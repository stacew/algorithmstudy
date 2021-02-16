#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/42746
//sort compare lambda( 숫자 비교 -> 붙인 문자 비교), case : zero full

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> NumberStrings(numbers.size());
	int zeroCount = 0; //case 11
	for (size_t i = 0; i < numbers.size(); i++) {
		NumberStrings[i] = to_string(numbers[i]);
		if (numbers[i] == 0)
			zeroCount++;
	}
	if (zeroCount == numbers.size())
		return "0";

	sort(NumberStrings.begin(), NumberStrings.end(), [](const string& left, const string& right) {
		return left + right > right + left;
		});

	for (const auto& s : NumberStrings) {
		answer += s;
	}

	return answer;
}