#include "header/StlHeaders.h"


//#include "header/완전탐색/소수 찾기.h"
//#include "header/완전탐색/카펫.h"
//#include "header/이분탐색/입국심사.h"
//#include "header/해시/위장.h"
//#include "header/그래프/가장 먼 노드.h"
//#include "header/스택,큐/기능개발.h"
#include "header/스택,큐/프린터.h"
#if 0
#include "header/탐욕법(Greedy)/조이스틱.h"
#include "header/탐욕법(Greedy)/큰 수 만들기.h"
#include "header/탐욕법(Greedy)/구명보트.h"


#include "header/동적계획법(Dynamic Programming)/N으로 표현.h"
#endif
#if 0
1. 해시, 정렬, 완전탐색, dfs / bfs
2. 스택 / 큐, 힙
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
	//최소값, 최대값, 빈값 테스트 케이스 확인
	//시간 있으면 브루트포스로 테스트 케이스 만들어서 비교해보기
#if 1
	abs(-1);
	cout << solution({ 2,1,3,2 }, 2) << ", " << 1 << endl;
	cout << solution({ 1, 1, 9,1,1,1 }, 0) << ", " << 5 << endl;
#endif
#if 0
	vector<int> progresses = { 93, 30, 55 };
	vector<int> speeds = { 1, 30, 5 };
	for (const auto& n : solution(progresses, speeds))
		cout << n << " , ";  //2,1
	auto s2 = solution({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 });
	for (const auto& n : s2)
		cout << n << " , ";  //1,3,2
	for (const auto& n : solution({ 1,11,1,1,1 }, { 100, 100, 100, 100,100 }))
		cout << n << " , ";
	cout << endl << "-----------------------" << endl;
	for (const auto& n : solution({ }, {}))
		cout << n << " , ";
	cout << endl << "-----------------------" << endl;
	for (const auto& n : solution({ 1,95,1 }, { 100, 4,30 }))
		cout << n << " , ";
#endif
#if 0

	int n = 6;
	vector<vector<int>> edge = { {3, 6}, { 4, 3 }, { 3, 2 }, { 1, 3 }, { 1, 2 }, { 2, 4 }, { 5, 2 } };
	cout << solution(n, edge) << endl;
#endif
#if 0
	vector<vector<string>> vvs1 = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };//5
	cout << solution(vvs1) << endl;
	vector<vector<string>> vvs2 = { {"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"} };//3
	cout << solution(vvs2) << endl;
	vector<vector<string>> vvs3 = { {"crow_mask", "face"} };
	cout << solution(vvs3) << endl;
#endif
#if 0
	vector<int> res = solution(10, 2);
	for (const auto& n : res)
		cout << n << ", ";//4,3
	cout << endl << "-----------------------" << endl;
	vector<int> res2 = solution(8, 1);
	for (const auto& n : res2)
		cout << n << ", ";//3,3
	cout << endl << "-----------------------" << endl;
	vector<int> res3 = solution(24, 24);
	for (const auto& n : res3)
		cout << n << ", ";//8,6
	cout << endl << "-----------------------" << endl;
	vector<int> res4 = solution(8, 1);
	for (const auto& n : res4)
		cout << n << ", ";
	cout << endl << "-----------------------" << endl;
	vector<int> res5 = solution(5000, 2000000);
	for (const auto& n : res5)
		cout << n << ", ";
#endif
#if 0
	cout << solution(8, 1) << endl;
	cout << "-----------------------" << endl;
	cout << solution(5000, 200000); << endl;
#endif
#if 0	
	vector<int> res = solution({ 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5 });
	for (const auto& n : res)
		cout << n << endl;
#endif

	//	cout << endl << endl;
}