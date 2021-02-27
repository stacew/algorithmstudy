#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/43105

#endif

int solution(vector<vector<int>> t) {
	int height = t.size();//size = height
	for (int i = 1; i < height; i++) { 
		t[i][0] += t[i - 1][0];
		t[i][t[i].size() - 1] += t[i - 1][t[i - 1].size() - 1];
		for (int j = 1; j < t[i].size() - 1; j++) {
			t[i][j] += max(t[i-1][j - 1], t[i-1][j]);
		}
	}

	return *max_element(t[height - 1].begin(), t[height - 1].end());;
}
#if 0
int main()
{
	cout << solution({ {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} }); //30
}
#endif