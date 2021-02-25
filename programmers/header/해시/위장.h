#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42578
umap, uset
���� accumulate, multiplies<int>()
#endif
int solution(vector<vector<string>> clothes) {
	unordered_map<string, unordered_set<string>> ums; //type, names //���� �̸� �ߺ� �� ���´ٰ� ��. -> int
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

#if 0
vector<vector<string>> vvs1 = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };//5
cout << solution(vvs1) << endl;
vector<vector<string>> vvs2 = { {"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"} };//3
cout << solution(vvs2) << endl;
vector<vector<string>> vvs3 = { {"crow_mask", "face"} };
cout << solution(vvs3) << endl;
#endif
