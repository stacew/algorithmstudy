#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42883
max_element(begin, end)
string.erase(begin, end)
distance(begin, end);//end - begin
string <=> num ( stoi(), to_string() )
#endif

string solution(string n, int removeK) {
	int pos = 0;
	while (pos + removeK < n.size()) { //1. 사이즈 check..
		auto begin = n.begin() + pos;
		auto maxiter = max_element(begin, begin + removeK + 1); //end iter까지 들어가서 1. 사이즈 check 주의
		if (begin != maxiter) {
			removeK -= distance(maxiter, begin );
			n.erase(begin, maxiter);
		}
		pos++;
	}
	n.erase(n.end() - removeK, n.end());
	return n;
}

string solution2(string number, int removable) {

	vector<int> removes;
	int startPos = 0;
	while (removable != 0) {
		int max = 0;
		int maxPos = startPos;
		int checkLen = startPos + removable + 1;
		if (checkLen > number.size())
			break;

		for (int i = startPos; i < checkLen; i++) {
			if (max < number[i] - '0') {
				max = number[i] - '0';
				maxPos = i;
			}
		}

		removable -= maxPos - startPos;
		for (int i = startPos; i < maxPos; i++) {
			removes.push_back(i);
		}
		startPos = maxPos + 1;
	}

	for (auto iter = removes.rbegin(); iter != removes.rend(); iter++)
		number.erase(*iter, 1);

	number.erase(number.size() - removable, removable);

	return number;
}