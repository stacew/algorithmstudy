#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42627
//�ð� �ѱ��
#endif

struct info {
	int req;
	int exe;
};
int solution(vector<vector<int>> jobs) {
	sort(jobs.begin(), jobs.end(), [](const vector<int>& l, const vector<int>& r) {
		return l[0] < r[0];
		});


	int answer = 0;
	auto comp = [](const info& l, const info& r) {
		return l.exe > r.exe; // ���� �� üũ
	};
	priority_queue<info, vector<info>, decltype(comp)> pq(comp);
	int endTime = 0;
	int jPos = 0;
	while (pq.empty() == false || jPos < jobs.size()) {
		if (pq.empty()) {
			endTime = jobs[jPos][0];
		}
		else {
			info topinfo = pq.top(); pq.pop();
			answer += (endTime + topinfo.exe) - topinfo.req;
			if (topinfo.req > endTime)
				endTime += topinfo.req;
			endTime += topinfo.exe;
		}

		while (jPos < jobs.size() && jobs[jPos][0] <= endTime) { //�ð��� üũ
			pq.push({ jobs[jPos][0], jobs[jPos][1] });
			jPos++;
		}
	}

	return answer / jobs.size();
}