#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42898
mod(1000000007) 조건 : 중간 계산 기록할 때 마다 나머지 처리를 하기
#endif


constexpr int mod = 1000000007;
int solution(int c, int r, vector<vector<int>> puddles) {

	vector<vector<int>> rows(r);
	for (int i = 0; i < rows.size(); i++)
		rows[i].resize(c);

	rows[0][0] = 1;
	for (const auto& p : puddles)
		rows[p[1] - 1][p[0] - 1] = -1;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (rows[i][j] == -1)
				continue;

			int left = j > 0 ? rows[i][j - 1] : -1;
			int top = i > 0 ? rows[i - 1][j] : -1;
			rows[i][j] += left > 0 ? left : 0;
			rows[i][j] += top > 0 ? top : 0;
			rows[i][j] %= mod;
		}
	}

	return rows[r - 1][c - 1];
}

#if 0
int main()
{
	cout << solution(4, 3, { {2,2} }); //4
}
#endif