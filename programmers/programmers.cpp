#include "header/StlHeaders.h"


#include "header/완전탐색/소수 찾기.h"
#if 0
#include "header/완전탐색/카펫.h"

#include "header/이분탐색/입국심사.h"

#include "header/해시/위장.h"

#include "header/스택,큐/기능개발.h"
#include "header/스택,큐/프린터.h"

#include "header/그래프/가장 먼 노드.h"

#include "header/탐욕법(Greedy)/조이스틱.h"
#include "header/탐욕법(Greedy)/큰 수 만들기.h"
#include "header/탐욕법(Greedy)/구명보트.h"


#include "header/동적계획법(Dynamic Programming)/N으로 표현.h"
#endif
#if 0
1. 해시, 정렬, 완전탐색, dfs/bfs
2. 스택/큐, 힙
3. DP, 그래프, 탐욕법, 이분탐색

해시 3
dfs, bfs 3, 3, 3
힙 3, 3
그래프 3, 5
DP 3, 3, 3, 4
이분탐색 4
탐욕법 3, 3
#endif





int main()
{
	vector<string> vs1 = { "leo", "kiki", "eden" };
	vector<string> vs2 = { "eden", "kiki" };
	vector<string> vs3 = { "12","999","99","123","1234","12345" };
	vector<string> vs4 = { "1234","99"};
	vector<string> vs5 = {};
	
	vector<int> vi1 = { 1, 5, 2, 6, 3, 7, 4, 10, 23, 12 };
	vector<int> vi2 = { 10 };
	vector<int> vi3 = { 10,10,10,10,10,10,10,10,10,10 };

	vector<vector<int>> vvi1 = { {2, 5, 3}, { 4, 4, 1 }, { 1, 7, 3 } };

	//cout << solution("1234") << endl;
	//cout << solution("4321") << endl;
	//cout << solution("67890") << endl;
	//cout << solution("09876") << endl;
	cout << solution("1232131345") << endl;
	cout << solution("17") << endl;
	cout << solution("011") << endl;
	
	
#if 0	
	vector<int> res = solution({ 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5 });
	for (const auto& n : res)
		cout << n << endl;
#endif

//	cout << endl << endl;
}