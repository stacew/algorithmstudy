#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42897
Circula 상태에서 최대 값 dp구하는 방법
맨 뒤를 지운다, 맨 앞을 지운다. 최대 값을 비교한다.
#endif


int solution(vector<int> money) {
	auto proc = [&money](int dp[3], int i) {
		int temp = money[i] + max(dp[0], dp[1]);
		dp[0] = dp[1]; dp[1] = dp[2]; dp[2] = temp;
	};

	int dp1[3] = { money[0], money[1], money[0] + money[2] };
	for (int i = 3; i < money.size() - 1; i++)
		proc(dp1, i);

	int dp2[3] = { 0, money[1], money[2] };
	for (int i = 3; i < money.size(); i++)
		proc(dp2, i);

	return max(max(dp1[1], dp1[2]), max(dp2[1], dp2[2]));
}


#if 0
int main()
{
	cout << solution({ 1,2,3,1 }); //4
	cout << endl;
	cout << solution({ 1,2,3,1,2,3,1 }); //7
	cout << endl;
	cout << solution({ 1,5,2,5,6,1,9,2,3,1 }); //23
	cout << endl;
	cout << solution({ 10,5,3,1,10,5,20 }); //35
	cout << endl;
}
#endif