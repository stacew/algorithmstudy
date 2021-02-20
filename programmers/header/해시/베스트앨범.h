#pragma once

#if 0
https://programmers.co.kr/learn/courses/30/lessons/42579
pair 보다 정보는 구조체 쓰는게 더 편하고 빠른 구현 되는 듯. pair 쓰지 말기..
vector 구조체 push_back { }
priority_queue 쓸 때, sort로 바꿀 생각 하기.
#endif

struct genCountIndex {
	string gen;
	int count;
	int index;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	unordered_map<string, int> genrePlayMap;
	vector< genCountIndex > infos;
	for (int i = 0; i < genres.size(); i++) {
		genrePlayMap[genres[i]] += plays[i];
		infos.push_back({ genres[i], plays[i], i });
	}

	sort(infos.begin(), infos.end(), [&](const genCountIndex& l, const genCountIndex& r) {
		if (genrePlayMap[l.gen] == genrePlayMap[r.gen]) {
			return l.count > r.count;
		}
		return genrePlayMap[l.gen] > genrePlayMap[r.gen];
		}
	);

	genrePlayMap.clear();
	vector<int> answer;	
	for (const auto& info : infos) {
		if (genrePlayMap[info.gen] == 2)
			continue;
		genrePlayMap[info.gen]++;
		answer.push_back(info.index);
	}

	return answer;
}