#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/49191
순위를 알려면 탐색 시, 전체적인 연결이 필요, 승리 방향을 바꿔서 양쪽 다 탐색 count를 확인.
unordered_map< int unordered_set >그래프
dfs( stack , visited )

#endif

struct info {
	unordered_set<int> lose;
	unordered_set<int> win;
};
int getCount(int i, unordered_map< int, info  >& graph, bool bWin) {
	int count = 0;
	vector<bool> visited(graph.size() + 1, false);
	stack<int> dfs;
	dfs.push(i);
	while (dfs.empty() == false) {
		int index = dfs.top();
		dfs.pop();

		for (const auto& next : bWin ? graph[index].win : graph[index].lose) {
			if (visited[next] == true)
				continue;
			visited[next] = true;
			dfs.push(next);
			count++;
		}
	}
	return count;
}

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	unordered_map< int, info  > graph;
	for (const auto& r : results) {
		graph[r[0]].win.insert(r[1]);
		graph[r[1]].lose.insert(r[0]);
	}

	for (int i = 1; i <= n; i++) {
		int count = getCount(i, graph, true);
		count += getCount(i, graph, false);
		if (count == n - 1)
			answer++;
	}
	return answer;
}