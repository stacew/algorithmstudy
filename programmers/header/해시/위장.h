#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42578
umap, uset
조합 accumulate, multiplies<int>()
#endif
int solution(vector<vector<string>> clothes) {
	unordered_map<string, unordered_set<string>> ums; //type, names //옷의 이름 중복 안 들어온다고 함. -> int
	for (const auto& c : clothes)
		ums[c[1]].insert(c[0]);

	vector<int> typeCounter;
	for (const auto& me : ums) {
		int count = 0;
		for (const auto& se : me.second) {
			count++;
		}
		typeCounter.push_back(count + 1); // count + 1. Combination not use
	}

	if (typeCounter.size() == 1)
		return typeCounter[0] - 1;

	return accumulate(typeCounter.begin(), typeCounter.end(), 1, multiplies<int>()) - 1;
}