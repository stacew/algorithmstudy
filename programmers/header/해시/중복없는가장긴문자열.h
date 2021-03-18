#pragma once
#if 0
//string s = "abcabcbb";	//3
//string s = "abcadbca";	//4 bcad, cadb, adbc
//string s = "abcde";		//5
//string s = "aab";			//2
//string s = "cccccccc";	//1
//string s = "abba";		//2
#endif

int solution(string s) {
	int maxLen = 0;
	int start = 0;
	unordered_map<char, int> umap;
	for (int i = 0; i < s.size(); i++) {

		auto item = umap.find(s[i]);
		if (item != umap.end() && item->second >= start) { // ***. 찾아도 Start 이전의 중첩된 것은 무시...

			maxLen = std::max(i - start, maxLen);
			start = item->second + 1; //중복된 인덱스 다음 인덱스부터 기준 길이를 갱신.
		}
		umap[s[i]] = i; //갱신						
	}
	maxLen = std::max((int)s.size() - start, maxLen);

	return maxLen;
}