#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/43163
bfs 최소 도착 리턴

#endif


int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	unordered_set< string > visited;

	queue<string> q;
	q.push(begin);
	visited.insert(begin);
	while (q.empty() == false) {
		int prevSize = q.size();
		answer += 1;
		if (q.front() == target)
			return answer - 1; //begin 제외

		for (int i = 0; i < prevSize; i++) {
			string front = q.front();
			q.pop();
			for (const auto& word : words) {
				if (visited.find(word) != visited.end())
					continue;

				int diff = 0;
				for (int i = 0; i < word.size(); i++) {
					if (word[i] != front[i]) {
						diff++;
						if (diff >= 2)
							continue;
					}
				}
				if (diff == 1) {
					q.push(word);
					visited.insert(word);
				}
			}
		}
	}
	return 0;
}

#if 0
solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
#endif