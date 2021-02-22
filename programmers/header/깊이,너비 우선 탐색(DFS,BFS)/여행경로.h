#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/43164
BackTrace recursion없이 Stack으로 풀기, Copy 필요 조건을 확실히 알기..
#endif


using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	unordered_map < string, vector< string > >  umap;
	for (const auto& t : tickets) {
		umap[t[0]].emplace_back(t[1]);
	}
	for (auto& u : umap) {
		sort(u.second.begin(), u.second.end(), greater<string>());
	}

	using VISITED = unordered_map < string, unordered_map< string, int > >;
	VISITED visited;
	for (const auto& t : tickets) {
		visited[t[0]][t[1]]++;
	}

	using STK = pair< vector<string>, VISITED >;
	stack< STK > stk;
	stk.push(STK({ "ICN" }, visited));//"ICN"....
	while (stk.empty() == false) {
		auto record = stk.top().first;
		auto visited = stk.top().second;
		if (record.size() == tickets.size() + 1)
			return record;

		stk.pop();
		auto startName = record[record.size() - 1];
		for (const auto& nextName : umap[startName]) {
			if (visited[startName][nextName] == 0)
				continue;

			visited[startName][nextName] --;
			record.push_back(nextName);
			stk.push(STK(record, visited));
			record.pop_back();
			visited[startName][nextName] ++;
		}
	}

	return answer;
}