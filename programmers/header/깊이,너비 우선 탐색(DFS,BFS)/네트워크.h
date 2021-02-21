#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/43162
따로 그래프 정보를 담아둘 필요는 없었음.
queue bfs, visited

#endif
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	queue<int> bfs;
	vector<bool> visited(n);
	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;
		answer++;

		visited[i] = true;
		bfs.push(i);
		while (bfs.empty() == false) {
			int prevSize = bfs.size();
			for (int k = 0; k < prevSize; k++) {
				int front = bfs.front();
				bfs.pop();

				for (int next = 0; next < computers[front].size(); next++) {
					if (visited[next] || computers[front][next] == 0)
						continue;
					visited[next] = true;
					bfs.push(next);
				}
			}
		}
	}

	return answer;
}

int solution_(int n, vector<vector<int>> computers) {
	int answer = 0;
	unordered_map< int, unordered_set<int> > graph;

	for (int i = 0; i < computers.size(); i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && computers[i][j] == 1)
				graph[i].insert(j);
		}
	}

	queue<int> bfs;
	vector<bool> visited(n);
	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;
		answer++;

		bfs.push(i);
		visited[i] = true;
		while (bfs.empty() == false) {
			int prevSize = bfs.size();
			for (int k = 0; k < prevSize; k++) {
				int front = bfs.front();
				bfs.pop();

				for (const auto& next : graph[front]) {
					if (visited[next])
						continue;

					bfs.push(next);
					visited[next] = true;
				}
			}
		}
	}

	return answer;
}