#pragma once

#if 0
https://programmers.co.kr/learn/courses/30/lessons/42579
pair ���� ������ ����ü ���°� �� ���ϰ� ���� ���� �Ǵ� ��. pair ���� ����..
vector ����ü push_back { }
priority_queue �� ��, sort�� �ٲ� ���� �ϱ�.
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